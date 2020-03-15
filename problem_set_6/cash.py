from cs50 import get_float

while True:
    change = get_float("Change owed: ")
    if change >= 0:
        cents = change * 100
        break

min_coins = 0

while cents > 0:
    while cents >= 25:
        min_coins += cents // 25
        cents %= 25
    while cents >= 10:
        min_coins += cents // 10
        cents %= 10
    while cents >= 5:
        min_coins += cents // 5
        cents %= 5
    while cents >= 1:
        min_coins += cents // 1
        cents %= 1

print(int(min_coins))
