// Coleman-Liau index

#include <stdio.h>
#include <cs50.h>
#include <string.h>

string get_text(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string text = get_text();
    count_letters(text);
    count_words(text);
    count_sentences(text);
}

string get_text(void)
{
    string text = get_string("Text: ");   
    return text;
}

int count_letters(string text)
{
    int letter_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If character is from A to Z, or from a to z
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letter_count++;
        }
    }
    printf("%i letter(s)\n", letter_count);
    return letter_count;
}

int count_words(string text)
{
    int word_count = 0;
    int space_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == 32)
        {
            space_count++;            
        }
    }
    word_count = space_count + 1;
    printf("%i word(s)\n", word_count);
    return word_count;
}

int count_sentences(string text)
{
    int sentence_count = 0;
    int end_character_count = 0;
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // If character is ! or . or ?
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            end_character_count++;
        }
    }
    sentence_count = end_character_count;
    printf("%i sentence(s)\n", sentence_count);
    return sentence_count;
}
