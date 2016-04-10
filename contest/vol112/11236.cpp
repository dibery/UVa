#include<cstdio>

int main()
{
	int N = 1000000;
	for( int a = 1; a <= 125; ++a )
		for( int b = a; b <= 592; ++b )
			for( int c = b, d; c <= 884 && a + b + c * 2 <= 2000; ++c )
				if( a * b * c > N
						&& ( a + b + c ) * N % ( a * b * c - N ) == 0
						&& ( d = ( a + b + c ) * N / ( a * b * c - N ) ) >= c
						&& a + b + c + d <= 2000 )
					printf( "%d.%02d %d.%02d %d.%02d %d.%02d\n", a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, d / 100, d % 100 );
}
