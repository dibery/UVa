for _ in range(int(input())):
	cap, trip, total = map(int, input().split())
	arr = [int(input()) for i in range(total)]
	time = count = 0
	for i in range(total % cap, total + 1, cap):
		if i:
			count += 1
			time = max(time, arr[i - 1]) + trip * 2
	print(time - trip, count)
