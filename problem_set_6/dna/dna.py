import csv
from sys import argv, exit

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

str_filename = argv[1]
dna_filename = argv[2]


def get_str_data(str_filename):

    with open(str_filename, "r") as str_file:
        str_read = csv.DictReader(str_file)

        row = next(str_read)

        str_data = []
        for key in row:
            str_data.append(key)
        str_data.pop(0)

    return str_data


def get_dna_str_count(dna_filename, str_data):

    with open(dna_filename, "r") as dna_file:
        dna_read = dna_file.read()

        dna_str_count = {}

        for str in str_data:
            str_count = 0
            str_max_count = 0
            i = 0
            str_length = len(str)

            while i < len(dna_read) - str_length:
                if dna_read[i:i+str_length] == str:
                    str_count += 1
                    if str_count > str_max_count:
                        str_max_count = str_count
                    i += str_length
                else:
                    str_count = 0
                    i += 1

            dna_str_count[str] = str_max_count

    return dna_str_count


def match_str(str_filename, str_data, dna_str_count):

    match_result = ""

    with open(str_filename, "r") as str_file:
        str_read = csv.DictReader(str_file)

        for row in str_read:
            match_str_count = 0

            for str in str_data:
                if int(row[str]) == dna_str_count[str]:
                    match_str_count += 1

            if match_str_count == len(str_data):
                match_result = row["name"]
                break

    if match_result == "":
        match_result = "No match"

    return match_result


str_data = get_str_data(str_filename)
dna_str_count = get_dna_str_count(dna_filename, str_data)
match_result = match_str(str_filename, str_data, dna_str_count)

print(match_result)
