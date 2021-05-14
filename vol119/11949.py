for _ in range(int(input())):
    reward = list(map(float, input().split()))
    reward[0] *= -1
    low, mid, high = -1, 0, 1
    while high - low > 1e-8:
        if sum(r / (1 + mid) ** seq for seq, r in enumerate(reward)) > 0:
            low = mid
        else:
            high = mid
        mid = (low + high) / 2
    print('%.3f%%' % (mid * 100))
