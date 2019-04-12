#include<cstdio>
#include<algorithm>

int time( int n, int div )
{
	int t = 0;
	while( n % div == 0 )
		n /= div, ++t;
	return n == 1? t : 0;
}

int main()
{
	int n;

	while( scanf( "%d", &n ) && n )
	{
		int t[ 100 ] = { 0 }, ans = 1, size = 0;
		for( int i = 2; i*i <= n && i < 46341; ++i )
			if( n % i == 0 )
				ans = std::max( time( n, i ), ans );
		if( n < 0 )
			for( int i = -2; i*i < -( long long int )n && -i < 46341; --i )
				if( n % i == 0 )
					ans = std::max( time( n, i ), ans );
		printf( "%d\n", ans );
	}
}
