from cs50 import get_string

text = get_string("Text: ")

# Coleman-Liau index
# L = average number of letters per 100 words in the text
# S = average number of sentences per 100 words in the text
index = 0.0588 * L - 0.296 * S - 15.8

letter_count
# Letters are any uppercase or lowercase alphabetic characters, 
# excluding any punctuation, digits, or other symbols

word_count
# A word is any sequence of characters separated by a space

sentence_count
# A sentence is any sequence of characters that ends with . or ! or ?

print()