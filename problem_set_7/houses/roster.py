import cs50
from sys import argv, exit

if len(argv) != 2:
    print("Usage: python roster.py house")
    exit(1)

house = argv[1]

db = cs50.SQL("sqlite:///students.db")

rows = db.execute("SELECT first, middle, last, birth \
                    FROM students \
                    WHERE house=? \
                    ORDER BY last, first", house)

for row in rows:
    first_name = row["first"]
    middle_name = row["middle"]
    last_name = row["last"]
    birth = row["birth"]

    if middle_name is None:
        print(first_name, last_name + ", born", str(birth))
    else:
        print(first_name, middle_name, last_name + ", born", str(birth))
