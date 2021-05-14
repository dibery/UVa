import sys

for i in sys.stdin:
    s, p, y, j = map(int, i.split())
    for r in range(3):
        if ( j + 12 + s + y + r ) % 3 == 0:
            age = ( j + 12 + s + y + r ) // 3
            if s + p == y:
                print(age, age - r // 2 - s, age - min(1, r) - y)
            else:
                print(age, age - min(1, r) - s, age - r // 2 - y)
