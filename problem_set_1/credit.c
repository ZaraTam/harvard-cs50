// Luhn's algorithm

#include <math.h>
#include <stdio.h>
#include <cs50.h>

long get_number(void);
int get_length(long number);
bool check_length(long number, int length);
string check_card_type(long number, int length, int digits[]);
bool check_checksum(long number, int length, int digits[]);
string validate_card(bool is_valid_length, string card_type, bool is_valid_checksum);

int main(void)
{
    long number = get_number();
    int length = get_length(number);
    bool is_valid_length = check_length(number, length);

    int digits[length];
    for (int i = 0; i < length; i++)
    {
        digits[i] = number % 10;
        printf("Number = %ld\n", number);
        printf("index = %i\n", i);
        printf("Digit = %i\n", digits[i]);
        printf("\n");
        number /= 10;
    }

    string card_type = check_card_type(number, length, digits);
    bool is_valid_checksum = check_checksum(number, length, digits);
    string card_validation = validate_card(is_valid_length, card_type, is_valid_checksum);

    printf("%s\n", card_validation);
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
    }
    else
    {
        is_valid_length = false;
    }
    return is_valid_length;
}

string check_card_type(long number, int length, int digits[])
{
    string card_type = "";

    // All Visa numbers start with 4
    if (length >= 1 && digits[length - 1] == 4)
    {
        card_type = "VISA";
    }

    // All American Express numbers start with 34 or 37
    if (length >= 2 && digits[length - 1] == 3
        && (digits[length - 2] == 4 || digits[length - 2] == 7))
    {
        card_type = "AMEX";
    }

    // Most MasterCard numbers start with 51, 52, 53, 54, or 55
    if (length >= 2 && digits[length - 1] == 5
        && (digits[length - 2] == 1 || digits[length - 2] == 2
            || digits[length - 2] == 3 || digits[length - 2] == 4
            || digits[length - 2] == 5))
    {
        card_type = "MASTERCARD";
    }

    return card_type;
}

bool check_checksum(long number, int length, int digits[])
{
    bool is_valid_checksum;

    int odd_digits_sum = 0;
    int even_digits_sum = 0;
    int product = 0;
    int sum_all = 0;
    int checksum = 0;

    for (int i = 1; i < length; i += 2)
    {
        product = digits[i] * 2;

        if (product >= 10)
        {
            even_digits_sum += 1 + product % 10;
        }
        else
        {
            even_digits_sum += product;
        }
    }

    for (int i = 0; i < length; i += 2)
    {
        odd_digits_sum += digits[i];
    }

    sum_all = even_digits_sum + odd_digits_sum;
    checksum = sum_all % 10;

    if (checksum == 0)
    {
        is_valid_checksum = true;
    }
    else
    {
        is_valid_checksum = false;
    }

    return is_valid_checksum;
}

string validate_card(bool is_valid_length, string card_type, bool is_valid_checksum)
{
    string card_validation = "";

    if (is_valid_length == true && is_valid_checksum == true)
    {
        card_validation = card_type;
    }
    else
    {
        card_validation = "INVALID";
    }

    return card_validation;
}
