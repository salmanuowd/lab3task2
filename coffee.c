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
