import csv
from sys import argv, exit

if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

str_filename = argv[1]
dna_filename = argv[2]

with open(str_filename, "r") as str_file:
    str_read = csv.DictReader(str_file)

    for row in str_read:
        print(row)
        name = row["name"]
        print(name)

    str_data = []
    for key in row:
        str_data.append(key)
    str_data.pop(0)
    print(str_data)

with open(dna_filename, "r") as dna_file:
    dna_read = dna_file.read()
    print(dna_read)

    dna_str_count = {}

    for str in str_data:
        str_count = 0
        str_max_count = 0
        i = 0
        str_length = len(str)

        while i < len(dna_read) - str_length:
            if dna_read[i:i+str_length] == str:

                print(str)
                print(dna_read[i:i+str_length])
                str_count += 1
                if str_count > str_max_count:
                    str_max_count = str_count
                i += str_length

                print("str_max_count =", str_max_count)
                print("str_count", str_count)

            else:
                str_count = 0
                i += 1

        dna_str_count[str] = str_max_count

    print(dna_str_count)
