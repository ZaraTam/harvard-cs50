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

    str = []
    for key in row:
        str.append(key)
    str.pop(0)
    print(str)

with open(dna_filename, "r") as dna_file:
    dna_read = dna_file.read()
    print(dna_read)
