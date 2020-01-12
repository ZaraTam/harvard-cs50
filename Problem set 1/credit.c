// Luhn's algorithm

#include <math.h>
#include <stdio.h>
#include <cs50.h>

long get_number(void);

int main(void)
{
    long number = get_number();
    
    int odd_place_sum = 0;
    int even_place_sum = 0;
    int sum = 0;
    int checksum = 0;

    int length = floor(log10(number)) + 1
    for (int i = 0; i < length; i++)
    {
        if (i + 1) % 2 == 0
        {
            digit = (number % 10^(i + 1)) / 10^i * 2
            even_place_sum += ;
        }
        else
        {
            digit = (number % 10^(i + 1)) / 10^i
            odd_place_sum += digit;
        }
    }
    printf("%li\n", odd_place_sum);
    printf("%li\n", even_place_sum);
    sum = odd_place_sum + even_place_sum;
    checksum = sum % 10;
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
