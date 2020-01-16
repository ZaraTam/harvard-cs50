#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

const int NUMBER_OF_ALPHABETS = 26;

bool validate_key(string key);
bool validate_length(string key, int n);
bool validate_alphabet(string key, int n);
bool validate_alphabet_once(string key, int n);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string key = argv[1];
        bool is_key_valid = validate_key(key);
        printf("Key valid? %i", is_key_valid);
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
    bool is_length_valid = validate_length(key, n);
    if (is_length_valid == true)
    {
        bool is_alphabet = validate_alphabet(key, n);
        if (is_alphabet == true)
        {
            bool is_alphabet_once = validate_alphabet_once(key, n);
            if (is_alphabet_once == true)
            {
                is_key_valid = true;
            }
            else
            {
                is_key_valid = false;
            }
        }
        else
        {
            is_key_valid = false;
        }
    }
    else
    {
        is_key_valid = false;
    }
    return is_key_valid;
}

bool validate_length(string key, int n)
{
    bool is_length_valid;
    if (n == NUMBER_OF_ALPHABETS)
    {
        is_length_valid = true;
    }
    else
    {
        is_length_valid = false;
        printf("Key must contain 26 characters\n");
    }
    return is_length_valid;
}

bool validate_alphabet(string key, int n)
{
    bool is_alphabet;
    int character_count = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(key[i]) != 0)
        {
            character_count++;
        }
    }
    if (character_count == n)
    {
        is_alphabet = true;
        printf("26 alphabetic characters\n");
    }
    else
    {
        is_alphabet = false;
        printf("Key must contain alphabetic characters only\n");
    }
    return is_alphabet;
}

bool validate_alphabet_once(string key, int n)
{
    bool is_alphabet_once;
    int alphabet_count[NUMBER_OF_ALPHABETS];
    for (int i = 0; i < NUMBER_OF_ALPHABETS; i++)
    {
        alphabet_count[i] = 0;
    }

    char upper_key[n];
    for (int i = 0; i < n; i++)
    {
        upper_key[i] = toupper(key[i]);
        alphabet_count[upper_key[i] - 65]++;
        printf("%i ", alphabet_count[upper_key[i] - 65]);
        if (alphabet_count[upper_key[i] - 65] > 1)
        {
            printf("Key must contain each alphabet exactly once\n");
            is_alphabet_once = false;
        }
        else
        {
            is_alphabet_once = true;
        }
    }
    return is_alphabet_once;
}