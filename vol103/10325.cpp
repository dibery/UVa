#include<cstdio>
#include<climits>

int bit( int n ) { return n? n % 2 + bit( n >> 1 ) : 0; }
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }
int mul( int factor[], int state, int n )
{
	long long int x = 1;
	for( int i = 0; 1 << i <= state && x <= n; ++i )
		if( state & 1 << i )
			x = x * factor[ i ] / gcd( x, factor[ i ] );
	return int( n / x );
}

int main()
{
	int n, size, lot[ 15 ];

	while( scanf( "%d %d", &n, &size ) == 2 )
	{
		int ans = n;
		for( int i = 0; i < size; ++i )
			scanf( "%d", lot+i );
		for( int i = 1; i < 1 << size; ++i )
		{
			int m = mul( lot, i, n );
			if( bit( i ) % 2 && m )
				ans -= m;
			else if( bit( i ) % 2 == 0 && m )
				ans += m;
		}
		printf( "%d\n", ans );
	}
}
