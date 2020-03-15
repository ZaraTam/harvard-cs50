from cs50 import get_string

text = get_string("Text: ")

# Coleman-Liau index
# L = average number of letters per 100 words in the text
# S = average number of sentences per 100 words in the text
L = 0
S = 0
index = 0.0588 * L - 0.296 * S - 15.8


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
    sentence_count += 1

    return sentence_count


letter_count = count_letters(text)
word_count = count_words(text)
sentence_count = count_sentences(text)

print("letter_count =", letter_count)
print("word_count =", word_count)
print("sentence_count =", sentence_count)

print()
