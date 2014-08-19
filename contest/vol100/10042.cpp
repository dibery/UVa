#include<cstdio>

long long int prime[ 3500 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int sod( int n )
{
	int ans = 0;
	while( n )
		ans += n % 10, n /= 10;
	return ans;
}

int main()
{
	int n, ans, t;

	for( int i = 3; i < 31700; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;
	for( scanf( "%d", &t ); t; --t )
	{
		scanf( "%d", &n );
		for( ans = n+1; ; ++ans )
		{
			int X = sod( ans ), Y = 0, tmp = ans;
			for( int i = 0; ans > 1 && i < size; ++i )
				while( tmp % prime[ i ] == 0 )
					tmp /= prime[ i ], Y += sod( prime[ i ] );
			if( tmp > 1 )
				Y += sod( tmp );
			if( X == Y && !isp( ans ) )
				break;
		}
		printf( "%d\n", ans );
	}
}
