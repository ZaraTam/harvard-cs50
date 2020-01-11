// Greedy algorithm

#include <math.h>
#include <stdio.h>
#include <cs50.h>

int get_change(void);
void min_coins(int);

int main(void)
{
    int cents = get_change();
    min_coins(cents);
}

int get_change(void)
{
    float dollars;
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    return cents;
}

void min_coins(int cents)
{
    int coins = 0;

    if (cents == 0)
    {
        coins = 0;
    }
    else
    {
        while (cents > 0)
        {
            while (cents >= 25)
            {
                coins += cents / 25;
                cents = cents % 25;
            }
            while (cents >= 10)
            {
                coins += cents / 10;
                cents = cents % 10;
            }
            while (cents >= 5)
            {
                coins += cents / 5;
                cents = cents % 5;
            }
            while (cents >= 1)
            {
                coins += cents / 1;
                cents = cents % 1;
            }
        }
    }
    printf("%i\n", coins);    
}
