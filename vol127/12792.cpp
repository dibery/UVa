#include<cstdio>

int main()
{
	for( int n, t, x; scanf( "%d", &n ) == 1; )
	{
		for( t = x = 0; !t || x; ++t )
			x = x < n / 2? x * 2 + 1 : x * 2 % n;
		printf( "%d\n", t );
	}
}
