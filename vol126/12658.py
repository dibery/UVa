import re
s = [input() for i in range(6)][4]
print(''.join(['213'[a.start() % 4] for a in re.finditer('\*', s)]))
