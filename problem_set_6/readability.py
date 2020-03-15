from cs50 import get_string

text = get_string("Text: ")


def count_letters(text):
# Letters are any uppercase or lowercase alphabetic characters, 
# excluding any punctuation, digits, or other symbols

    letter_count = 0

    for letter in text:
        if letter.isalpha() == True:
            letter_count += 1

    return letter_count


def count_words(text):
# A word is any sequence of characters separated by a space

    word_count = 0
    space_count = 0

    for letter in text:
        if letter == " ":
            space_count += 1

    word_count = space_count + 1

    return word_count


def count_sentences(text):
# A sentence is any sequence of characters that ends with . or ! or ?

    sentence_count = 0
    end_of_sentence_characters = [".", "!", "?"]

    for letter in text:
        if letter in end_of_sentence_characters:
            sentence_count += 1

    return sentence_count


letter_count = count_letters(text)
word_count = count_words(text)
sentence_count = count_sentences(text)

# Coleman-Liau index
# L = average number of letters per 100 words in the text
# S = average number of sentences per 100 words in the text
L = letter_count / word_count * 100
S = sentence_count / word_count * 100
index = 0.0588 * L - 0.296 * S - 15.8
grade = round(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print("Grade", grade)
