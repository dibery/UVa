all = [0, 1, 3]
while len(all) <= 30:
    all.append(all[-1] + all[-2] * 2)

sym = [0, 1, 3, 1, 5]
while len(sym) <= 30:
    sym.append(sym[-2] + sym[-4] * 2)

for i in range(int(input())):
    n = int(input())
    print((all[n] - sym[n]) // 2 + sym[n])