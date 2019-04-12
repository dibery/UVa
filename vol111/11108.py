import sys

def test(S, p, q, r, s, t):
	S = S.replace('p', p).replace('q', q).replace('r', r).replace('s', s).replace('t', t)[::-1]
	stack = []
	for i in S:
		if i in 'TF':
			stack.append(i)
		elif i == 'N':
			stack[-1] = 'T' if stack[-1] == 'F' else 'F'
		else:
			a, b = stack.pop(), stack.pop()
			if i == 'K':
				stack.append('T' if a == b == 'T' else 'F')
			elif i == 'A':
				stack.append('F' if a == b == 'F' else 'T')
			elif i == 'C':
				stack.append('F' if a > b else 'T')
			else:
				stack.append('T' if a == b else 'F')
	return stack[0] == 'T'

c = ['T', 'F']
for S in sys.stdin:
	S = S.strip()
	if S != '0':
		print('tautology' if all(test(S, p, q, r, s, t) for p in c for q in c for r in c for s in c for t in c) else 'not')
