import csv
import cs50
from sys import argv, exit

if len(argv) != 2:
    print("Usage: python import.py characters.csv")
    exit(1)

db = cs50.SQL(sqlite:///students.db)

with open("characters.csv", "r") as characters:
    reader = csv.DictReader(characters)

    for row in reader:
        print(row)

        name = row["name"].split(" ")
        if len(name) == 2:
            first_name = name[0]
            last_name = name[1]
            print("first_name", first_name)
            print("last_name", last_name)
        elif len(name) == 3:
            first_name = name[0]
            middle_name = name[1]
            last_name = name[2]
            print("first_name", first_name)
            print("middle_name", middle_name)
            print("last_name", last_name)

        birth = int(row["birth"])
        print(birth)

        db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                    first_name, middle_name, last_name, row["house"], birth))
