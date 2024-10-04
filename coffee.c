#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#define ADMIN_PASSWORD "1234"
#define ESPRESSO_PRICE 3.5
#define CAPPUCCINO_PRICE 4.5
#define MOCHA_PRICE 5.5
#define ESPRESSO_BEANS 8
#define ESPRESSO_WATER 30
#define CAPPUCCINO_BEANS 8
#define CAPPUCCINO_WATER 30
#define CAPPUCCINO_MILK 70
#define MOCHA_BEANS 8
#define MOCHA_WATER 39
#define MOCHA_MILK 160
#define MOCHA_SYRUP 30
#define LOW_THRESHOLD_BEANS 10
#define LOW_THRESHOLD_WATER 50
#define LOW_THRESHOLD_MILK 20
#define LOW_THRESHOLD_SYRUP 10
int coffee_beans = 100; 
int water = 500;
int milk = 300;
int chocolate_syrup = 150;
float total_sales = 0.0;
void orderCoffee() {
    int coffee_choice;
    float price = 0;
    printf("\nAvailable Coffee Types:\n");
    if (coffee_beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) {
        printf("1. Espresso - %.2f AED\n", ESPRESSO_PRICE);
    } else {
        printf("1. Espresso - Unavailable due to insufficient ingredients\n");
    }

    if (coffee_beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
        printf("2. Cappuccino - %.2f AED\n", CAPPUCCINO_PRICE);
    } else {
        printf("2. Cappuccino - Unavailable due to insufficient ingredients\n");
    }

    if (coffee_beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && chocolate_syrup >= MOCHA_SYRUP) {
        printf("3. Mocha - %.2f AED\n", MOCHA_PRICE);
    } else {
        printf("3. Mocha - Unavailable due to insufficient ingredients\n");
    }
printf("0. Cancel\n");
    printf("Please select a coffee (1-3) or 0 to cancel: ");
    scanf("%d", &coffee_choice);
    switch (coffee_choice) {
        case 1:
            if (coffee_beans >= ESPRESSO_BEANS && water >= ESPRESSO_WATER) {
                price = ESPRESSO_PRICE;
                coffee_beans -= ESPRESSO_BEANS;
                water -= ESPRESSO_WATER;
                printf("You ordered Espresso for %.2f AED\n", price);
            } else {
                printf("Sorry, Espresso is unavailable.\n");
                return;
            }
            break;
        case 2:
            if (coffee_beans >= CAPPUCCINO_BEANS && water >= CAPPUCCINO_WATER && milk >= CAPPUCCINO_MILK) {
                price = CAPPUCCINO_PRICE;
                coffee_beans -= CAPPUCCINO_BEANS;
                water -= CAPPUCCINO_WATER;
                milk -= CAPPUCCINO_MILK;
                printf("You ordered Cappuccino for %.2f AED\n", price);
            } else {
                printf("Sorry, Cappuccino is unavailable.\n");
                return;
            }
            break;
        case 3:
            if (coffee_beans >= MOCHA_BEANS && water >= MOCHA_WATER && milk >= MOCHA_MILK && chocolate_syrup >= MOCHA_SYRUP) {
                price = MOCHA_PRICE;
                coffee_beans -= MOCHA_BEANS;
                water -= MOCHA_WATER;
                milk -= MOCHA_MILK;
                chocolate_syrup -= MOCHA_SYRUP;
                printf("You ordered Mocha for %.2f AED\n", price);
            } else {
                printf("Sorry, Mocha is unavailable.\n");
                return;
            }
            break;
        case 0:
            printf("Order cancelled.\n");
            return;
        default:
            printf("Invalid selection. Try again.\n");
            return;
    }
    float payment = 0.0;
    float inserted_coin;
    printf("Please insert %.2f AED: ", price);
    while (payment < price) {
        scanf("%f", &inserted_coin);
        if (inserted_coin == 1.0 || inserted_coin == 0.5) {
            payment += inserted_coin;
            printf("Inserted: %.2f AED, Total: %.2f AED\n", inserted_coin, payment);
        } else {
            printf("Invalid coin. Insert 1.0 or 0.5 AED.\n");
        }
    }
    printf("Payment complete. Your change: %.2f AED\n", payment - price);
    total_sales += price;
    if (coffee_beans <= LOW_THRESHOLD_BEANS) printf("Warning: Low on coffee beans!\n");
    if (water <= LOW_THRESHOLD_WATER) printf("Warning: Low on water!\n");
    if (milk <= LOW_THRESHOLD_MILK) printf("Warning: Low on milk!\n");
    if (chocolate_syrup <= LOW_THRESHOLD_SYRUP) printf("Warning: Low on chocolate syrup!\n");
}
void adminMode() {
    char password[20];
    printf("Enter admin password: ");
    scanf("%s", password);
    if (strcmp(password, ADMIN_PASSWORD) != 0) {
        printf("Incorrect password. Access denied.\n");
        return;
    }
    int admin_choice;
    while (1) {
        printf("\nAdmin Menu:\n");
        printf("1. Display ingredient levels and total sales\n");
        printf("2. Replenish ingredients\n");
        printf("3. Reset total sales\n");
        printf("0. Exit admin mode\n");
        printf("Enter your choice: ");
        scanf("%d", &admin_choice);
        switch (admin_choice) {
            case 1:
                printf("\nCurrent ingredient levels:\n");
                printf("Coffee Beans: %d grams\n", coffee_beans);
                printf("Water: %d milliliters\n", water);
                printf("Milk: %d milliliters\n", milk);
                printf("Chocolate Syrup: %d milliliters\n", chocolate_syrup);
                printf("Total Sales: %.2f AED\n", total_sales);
                break;
                 case 2:
                coffee_beans = rand() % 100 + 100; 
                water = rand() % 500 + 500;         
                milk = rand() % 300 + 200;          
                chocolate_syrup = rand() % 200 + 100; 
                printf("Ingredients replenished!\n");
                break;
                case 3:
                total_sales = 0;
                printf("Total sales reset to 0. Don't forget to collect the money!\n");
                break;
                
            case 0:
                // Exit admin mode
                printf("Exiting admin mode.\n");
                return;
                
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
int main() {
    int choice;
     while (1) {
        printf("\nMain Menu:\n");
        printf("1. Order Coffee\n");
        printf("2. Admin Mode\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                orderCoffee();
                break;
            case 2:
                adminMode();
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}
