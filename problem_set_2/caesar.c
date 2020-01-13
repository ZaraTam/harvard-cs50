#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string k = argv[1];
//         for (int i = 0, n = strlen(argv[1]); i < n; i++)
//         {
//             if (isdigit(argv[1][i]))
//             {
//                 return 0;
//             }
//             else
//             {
//                 return 1;
//             }
//         }
        
        int key = atoi(k);
        printf("k = %s\n", k);
        printf("key = %i\n", key);
        printf("key mod 26 = %i\n", key % 26);
        string plaintext = get_string("plaintext: ");
        printf("plaintext = %c\n", plaintext[0]);


        string ciphertext = "";
        for (int i = 0, n = strlen(plaintext); i < n; i++)
        {
            // If character is from A to Z, or from a to z
            if ((plaintext[i] >= 65 && plaintext[i] <= 90) || (plaintext[i] >= 97 && plaintext[i] <= 122))
            {
                ciphertext[i] = plaintext[i] + key % 26;
                // TODO handle wrapping around alphabetically, e.g. Z as A
            }
            else
            {
                ciphertext[i] = plaintext[i];
            }
        }
        printf("ciphertext: %s\n", ciphertext);
        return 0;
    }
    else if (argc == 1)
    {
        printf("Empty input\n");
        return 1;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
