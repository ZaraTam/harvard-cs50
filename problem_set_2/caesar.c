#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int check_argument(string k);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        check_argument(k);

        int key = atoi(k) % 26;
        printf("k = %s\n", k);
        printf("key = %i\n", key);
        string plaintext = get_string("plaintext: ");
        string ciphertext = "";
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // If character is from A to Z, or from a to z
            if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122))
            {
                ciphertext[i] = plaintext[i] + key;
                // TODO handle wrapping around alphabetically, e.g. Z as A
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
            printf("ciphertext: %s\n", ciphertext);
            return 0;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

int check_argument(string k)
{
    for (int i = 0, n = strlen(k); i < n; i++)
        {
            if (isdigit(k[i]) != 0)
            {
                printf("Digit\n");
            }
            else
            {
                printf("Not digit\n");
                return 1;
            }
        }
    // TODO turn string to int only if argument is all digits
    int key = atoi(k) % 26;
    return key;
}
