from cs50 import get_string

card_number = get_string("Number: ")

# American Express uses 15-digit numbers
# MasterCard uses 16-digit numbers
# Visa uses 13- and 16-digit numbers
card_number_length = [13, 15, 16]

# All American Express numbers start with 34 or 37
# Most MasterCard numbers start with 51, 52, 53, 54, or 55
# All Visa numbers start with 4
amex_start_digits = [34, 37]
mastercard_start_digits = [51, 52, 53, 54, 55]
visa_start_digits = [4]


def check_length(card_number):

    length = len(card_number)
    print("Length =", length)
    if length in card_number_length:
        is_valid_length = True
    else:
        is_valid_length = False

    return is_valid_length


def check_start_digits(card_number):
    print("Start digits =", card_number[0:2])

    if (int(card_number[0:2]) in amex_start_digits 
            or int(card_number[0:2]) in mastercard_start_digits 
            or int(card_number[0:1]) in visa_start_digits):
        is_valid_start_digits = True
    else:
        is_valid_start_digits = False

    return is_valid_start_digits


is_valid_length = check_length(card_number)
is_valid_start_digits = check_start_digits(card_number)
print("Length:", is_valid_length)
print("Start digits:", is_valid_start_digits)

if is_valid_length and is_valid_start_digits == True:
    is_card_valid = True
    print("VALID")
else:
    is_card_valid = False
    print("INVALID")
