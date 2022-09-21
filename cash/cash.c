#include "cs50.h"
#include <stdio.h>
#include <stdbool.h>
int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    bool found = false;
    int cent;
    while(found == false)
    {
        cent = get_int("Enter no. of cents that you are owed: ");
        if(cent < 0)
        {
            found = false;
        }
        else
        {
            found = true;
        }
    }
    return cent;
}

int calculate_quarters(int cents)
{
    int quart = cents / 25 ;
    return quart;
}

int calculate_dimes(int cents)
{
    int dime = cents / 10;
    return dime;
}

int calculate_nickels(int cents)
{
    int nickel = cents / 5;
    return nickel;
}

int calculate_pennies(int cents)
{
    int penny = cents;
    return penny;
}
