from math import factorial as f
def sol(order, seq):
    if len(order) == 1:
        return order
    next_fac = f(len(order) - 1)
    step = sol(order[1:], seq % next_fac)
    return step[:seq // next_fac] + order[0] + step[seq // next_fac:]
for i in range(int(input())):
    order, seq = input().split()
    print('Case %d: %s' % (i + 1, sol(order, int(seq) - 1)))
