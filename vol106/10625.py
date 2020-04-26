from collections import Counter
from operator import add
from functools import reduce

for c in range(int(input())):
    rule = {i[0]: Counter(i[1]) for i in [input().split('->') for j in range(int(input()))]}
    for q in range(int(input())):
        init, target, rep = (lambda x: (Counter(x[0]), x[1], int(x[2])))(input().split())
        for i in range(rep):
            new = reduce(add, (Counter({x: rule[j][x] * init[j] for x in rule[j]}) for j in init if j in rule), Counter())
            init = Counter({x: init[x] for x in init if x not in rule}) + new
        print(init[target])
