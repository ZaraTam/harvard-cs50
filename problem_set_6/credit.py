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

    if length in card_number_length:
        is_valid_length = True
    else:
        is_valid_length = False

    return is_valid_length


def check_card_type(card_number):

    card_type = ""

    if int(card_number[0:2]) in amex_start_digits:
        card_type = "AMEX"
    elif int(card_number[0:2]) in mastercard_start_digits:
        card_type = "MASTERCARD"
    elif int(card_number[0:1]) in visa_start_digits:
        card_type = "VISA"

    return card_type


def check_checksum(card_number):

    length = len(card_number)
    odd = []
    even = []
    even_products = []
    even_digits = []
    odd_digits = []

    for i in range(-1, -(length + 1), -2):
        odd.append(i)

    for i in range(-2, -(length + 1), -2):
        even.append(i)

    for i in even:
        even_products.append(int(card_number[i]) * 2)

    for i in range(len(even_products)):
        if even_products[i] >= 10:
            even_digits.append(1)
            even_digits.append(even_products[i] % 10)
        else:
            even_digits.append(even_products[i])

    for i in odd:
        odd_digits.append(int(card_number[i]))

    sum_even = sum(even_digits)
    sum_odd = sum(odd_digits)
    sum_all = sum_even + sum_odd

    checksum = sum_all % 10

    if checksum == 0:
        is_valid_checksum = True
    else:
        is_valid_checksum = False

    return is_valid_checksum


def validate_card(is_valid_length, card_type, is_valid_checksum):

    if is_valid_length == True and is_valid_checksum == True:
        card_validation = card_type
    else:
        card_validation = "INVALID"

    return card_validation


is_valid_length = check_length(card_number)
card_type = check_card_type(card_number)
is_valid_checksum = check_checksum(card_number)
card_validation = validate_card(is_valid_length, card_type, is_valid_checksum)

print(card_validation)
