import csv
from sys import argv, exit

if len(argv) != 3:
    print("Missing command line arguments")
    exit(1)

str_filename = argv[1]
dna_filename = argv[2]

with open(str_filename, "r") as str_file:
    str_read = str_file.read()
    print(str_read)

with open(dna_filename, "r") as dna_file:
    dna_read = dna_file.read()
    print(dna_read)
