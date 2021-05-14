from os.path import commonprefix

for _ in range(int(input())):
	word = [input() for i in range(int(input()))]
	last = word.pop(0)
	order, cost = [last], len(last)
	while word:
		w = [len(commonprefix((last, i))) for i in word]
		pos = w.index(max(w))
		cost += len(word[pos]) - w[pos]
		last = word.pop(pos)
		order.append(last)
	print(cost, *order, sep='\n')
