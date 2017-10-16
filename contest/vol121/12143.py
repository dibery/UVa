import fileinput

for x in fileinput.input():
    x = int( x )
    if x > 0:
        print( ( 107*x**10 - 690*x**8 + 1491*x**6 - 2060*x**4 + 1152*x**2 ) // 22680 % 10007 )
