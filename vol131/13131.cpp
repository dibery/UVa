#include<cstdio>

int main()
{
	int t, n, k;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &n, &k ); )
	{
		int s = 0;
		for( int i = 1; i * i <= n; ++i )
			if( n % i == 0 )
				s += i * ( i % k != 0 ) + n / i * ( n / i % k != 0 && i * i != n );
		printf( "%d\n", s );
	}
}
