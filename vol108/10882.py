for i in range(int(input())):
    n = list(map(int, input().split()))
    if sum(n) - min(n) * 2 <= 100:
        print('Case #%d: Between %d and %d times.' % (i + 1, max(0, (sum(n) - 99) // 2), min(n)))
    else:
        print('Case #%d: The records are faulty.' % (i + 1))
