from queue import Queue
import sys

def step(s):
	return [s[:i] + n + s[i + 1:] for i in range(len(s)) for n in 'abcdefghijklmnopqrstuvwxyz']

def out(s, path):
	if path[s]:
		out(path[s], path)
	print(s)

word_list, first = set(), True
while True:
	s = input()
	if s:
		word_list.add(s)
	else:
		break

for i in sys.stdin.readlines():
	first = False if first else print()
	s, t = i.strip().split()
	bfs = Queue()
	bfs.put(s)
	path = {s: None}
	while bfs.qsize() and t not in path:
		f = bfs.get()
		for n in step(f):
			if n not in path and n in word_list:
				bfs.put(n)
				path[n] = f
	if t in path:
		out(t, path)
	else:
		print('No solution.')
