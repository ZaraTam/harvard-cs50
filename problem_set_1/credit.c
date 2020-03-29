// Luhn's algorithm

#include <math.h>
#include <stdio.h>
#include <cs50.h>

long get_number(void);
int get_length(long number);
bool check_length(long number, int length);
string check_card_type(long number, int length);

int main(void)
{
    long number = get_number();
    int length = get_length(number);
    bool is_valid_length = check_length(number, length);
    string card_type = check_card_type(number, length);
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

int get_length(long number)
{
    int length;

    if (number != 0)
    {
        length = floor(log10(number)) + 1;
    }
    else
    {
        length = 1;
    }
    return length;
}

bool check_length(long number, int length)
{
    bool is_valid_length;

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

string check_card_type(long number, int length)
{
    string card_type;
    int numbers[length];

    // All American Express numbers start with 34 or 37
    // Most MasterCard numbers start with 51, 52, 53, 54, or 55
    // All Visa numbers start with 4

    for (int i = 0; i < length; i++)
    {
        numbers[i] = number % 10;
        printf("Number %lu\n", number);
        printf("Digit %i\n", numbers[i]);
        number /= 10;
    }

    card_type = "Invalid";
    return card_type;
}
