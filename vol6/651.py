import sys

ans = [0]
for i in range(1, 100000):
    ans.append(ans[-1] + 0.5 / i)
print('# Cards Overhang')
for i in map(int, sys.stdin):
    print('%5d     %.3f' % (i, ans[i]))
