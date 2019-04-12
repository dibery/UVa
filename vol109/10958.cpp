#include<cstdio>
#include<cstdlib>

int main()
{
	for( int m, n, p, t = 0; scanf( "%d %d %d", &m, &n, &p ) && ( m || n || p ); )
	{
		int ans = 0;
		long long v = (long long) p * p * abs( m ) * abs( n );
		for( long long i = 1; i * i <= v; ++i )
			if( v % i == 0 )
				ans += i * i == v? 1 : 2;
		printf( "Case %d: %d\n", ++t, ans * 2 - 1 );
	}
}
