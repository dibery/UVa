from math import *

def gcd_ext(a, b):
    a, sign_a, b, sign_b = abs(a), a < 0, abs(b), b < 0
    x, y, r = [1, 0], [0, 1], [a, b]
    while r[1]:
        q = r[0] // r[1]
        r = [r[1], r[0] % r[1]]
        x = [x[1], x[0] - q * x[1]]
        y = [y[1], y[0] - q * y[1]]
    return (x[0] * (-1 if sign_a else 1), y[0] * (-1 if sign_b else 1), r[0])

def up(n):
    return n + ((10 - n % 10) % 10)

def down(n):
    return n - n % 10

for i in range(int(input())):
    x1, y1, x2, y2 = map(lambda x: int(x.replace('.', '')), input().split())
    dx, dy = x2 - x1, y2 - y1
    if dx == 0:
        print(0 if x1 % 10 else (down(max(y1, y2)) - up(min(y1, y2))) // 10 + 1)
    elif dy == 0:
        print(0 if y1 % 10 else (down(max(x1, x2)) - up(min(x1, x2))) // 10 + 1)
    elif (dy * x1 - dx * y1) % 10:
        print(0)
    else:
        a, b, g = gcd_ext(dx, dy)
        val = (dy * x1 - dx * y1) // 10
        if val % g:
            print(0)
        else:
            dx, dy, val = dx // g, dy // g, val // g
            a, b = b * val, -a * val
            print(floor((x2 / 10 - a) / dx) - ceil((x1 / 10 - a) / dx) + 1)
