#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

bool validate_key(string key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        bool is_key_valid = validate_key(key);
        printf("%i", is_key_valid);
    printf("\n");
    return 0;
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

bool validate_key(string key)
{
    bool is_key_valid;
    int n = strlen(key);
    int character_count = 0;
    if (n == 26)
    {
        for (int i = 0; i < n; i++)
        {
            if (isalpha(key[i]) != 0)
            {
                character_count++;
            }
        }
        if (character_count == n)
        {
            printf("26 alphabetic characters\n");

            int alphabet_count[26];
            for (int i = 0; i < 26; i++)
            {
                alphabet_count[i] = 0;
            }

            char upper_key[26];
            for (int i = 0; i < n; i++)
            {
                upper_key[i] = toupper(key[i]);
                alphabet_count[upper_key[i] - 65]++;
                printf("%i ", alphabet_count[upper_key[i] - 65]);
                if (alphabet_count[upper_key[i] - 65] > 1)
                {
                    printf("Key must contain each alphabet exactly once\n");
                    is_key_valid = false;
                }
                else
                {
                    is_key_valid = true;
                }
            }
        }
        else
        {
            printf("Key must contain alphabetic characters only\n");
            is_key_valid = false;
        }
    }
    else
    {
        printf("Key must contain 26 characters\n");
        is_key_valid = false;
    }
    printf("%i\n", is_key_valid);
    return is_key_valid;
}
