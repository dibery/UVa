import itertools, sys, fractions

grp = {fractions.Fraction(int(''.join(i), 3), 80) for i in itertools.product('02', repeat=4)}
for i in sys.stdin.readlines()[:-1]:
    print('%sMEMBER' % ('' if fractions.Fraction(i) in grp else 'NON-'))
