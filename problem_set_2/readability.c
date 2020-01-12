// Coleman-Liau index

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <cs50.h>

string get_text(void);
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int get_grade(int letter_count, int word_count, int sentence_count);

int main(void)
{
    string text = get_text();
    int letter_count = count_letters(text);
    int word_count = count_words(text);
    int sentence_count = count_sentences(text);
    get_grade(letter_count, word_count, sentence_count);
}

string get_text(void)
{
    string text;
    do
    {
        text = get_string("Text: ");
    }
    while (strlen(text) == 0);
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
    return sentence_count;
}

int get_grade(int letter_count, int word_count, int sentence_count)
{
    float average_letters = 100 / (float) word_count * (float) letter_count;
    float average_sentences = 100 / (float) word_count * (float) sentence_count;
    float index = 0.0588 * average_letters - 0.296 * average_sentences - 15.8;
    int grade = roundf(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
    return grade;
}
