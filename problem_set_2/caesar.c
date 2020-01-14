#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool check_argument(string k);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
        int key;
        bool is_argument_valid = check_argument(k);

        if (is_argument_valid == true)
        {
            key = atoi(k) % 26;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        
        printf("k = %s\n", k);
        printf("key = %i\n", key);
        string plaintext = get_string("plaintext: ");
        string ciphertext = plaintext;
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // If character is from A to Z, or from a to z
            if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122))
            {
                ciphertext[i] = ((plaintext[i] + key) % 26);
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

bool check_argument(string k)
{
    int digit_count = 0;
    bool is_argument_valid;
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (isdigit(k[i]) != 0)
        {
            digit_count++;
            printf("Digit\n");
        }
        else
        {
            printf("Not digit\n");
            
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
