from cs50 import get_float

while True:
    change = get_float("Change owed: ") * 100
    if change >= 0:
        break

coin_count = 0

while change > 0:
    while change >= 25:
        coin_count += change // 25
        change %= 25
    while change >= 10:
        coin_count += change // 10
        change %= 10
    while change >= 5:
        coin_count += change // 5
        change %= 5
    while change >= 1:
        coin_count += change // 1
        change %= 1

print(int(coin_count))
