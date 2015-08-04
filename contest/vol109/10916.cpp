#include<cstdio>
#include<cmath>

int main()
{
	for( int year, stone, ans = 0; scanf( "%d", &year ) && year; ans = 0 )
	{
		stone = 1 << ( year - 1960 ) / 10 + 2;
		for( double sum = 0; sum < stone; )
			sum += log2( ++ans );
		printf( "%d\n", --ans );
	}
}
