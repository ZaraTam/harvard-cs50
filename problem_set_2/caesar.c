#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool validate_argument(string k);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        int key;
        bool is_argument_valid = validate_argument(k);

        if (is_argument_valid == true)
        {
            key = atoi(k) % 26;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }

        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // If character is from A to Z
            if (plaintext[i] >= 65 && plaintext[i] <= 90)
            {
                printf("%c", (plaintext[i] - 65 + key) % 26 + 65);
            }
            // If character is from a to z
            else if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
                printf("%c", (plaintext[i] - 97 + key) % 26 + 97);
            }
            else
            {
                printf("%c", plaintext[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool validate_argument(string k)
{
    int digit_count = 0;
    bool is_argument_valid;
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isdigit(k[i]) != 0)
        {
            digit_count++;
        }
    }
    if (digit_count == strlen(k))
    {
        is_argument_valid = true;
    }
    else
    {
        is_argument_valid = false;
    }
    return is_argument_valid;
}
