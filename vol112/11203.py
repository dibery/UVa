def judge(s):
	if set(s) != {"M", "E", "?"} or s.count('E') != 1 or s.count('M') != 1 or s.index("M") > s.index("E"):
		return False
	s = s.split('M')
	s[1] = s[1].split('E')
	return len(s[0]) + len(s[1][0]) == len(s[1][1]) and len(s[1][0]) and len(s[0])

for i in range(int(input())):
	print('theorem' if judge(input()) else 'no-theorem')
