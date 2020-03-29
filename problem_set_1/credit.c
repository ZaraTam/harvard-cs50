// Luhn's algorithm

#include <math.h>
#include <stdio.h>
#include <cs50.h>

long get_number(void);
bool check_length(long number);


int main(void)
{
    long number = get_number();
    bool is_valid_length = check_length(number);
}

long get_number(void)
{
    long number;
    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);
    return number;
}


bool check_length(long number)
{
    bool is_valid_length;
    int length;

    if (number != 0)
    {
        length = floor(log10(number)) + 1;
    }
    else
    {
        length = 1;
    }

    // American Express uses 15-digit numbers
    // MasterCard uses 16-digit numbers
    // Visa uses 13- and 16-digit numbers
    if (length == 13 || length == 15 || length == 16)
    {
        is_valid_length = true;
        printf("Valid length\n");
    }
    else
    {
        is_valid_length = false;
        printf("Invalid length\n");
    }
    return is_valid_length;
}
