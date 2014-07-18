#include<cstdio>
#include<cmath>

int prime[ 3000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}
int time( int& n, int& div )
{
	int t = 0;
	while( n % div == 0 )
		++t, n /= div;
	return t;
}

int main()
{
	int t, a, c;

	for( int i = 3; i < 3162; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	for( scanf( "%d", &t ); t; --t )
	{
		scanf( "%d %d", &a, &c );
		if( c % a != 0 )
			puts( "NO SOLUTION" );
		else
		{
			int first[ 3000 ] = { 0 }, last[ 3000 ] = { 0 }, second[ 3000 ] = { 0 }, ans = 1;
			for( int i = 0; i < size; ++i )
				first[ i ] = time( a, prime[ i ] );
			c /= a;
			for( int i = 0; i < size; ++i )
				last[ i ] = time( c, prime[ i ] );
			for( int i = 0; i < size; ++i )
				if( last[ i ] > first[ i ] )
					second[ i ] = last[ i ];
			for( int i = 0; i < size; ++i )
				ans *= pow( prime[ i ], second[ i ] );
			printf( "%d\n", ans * c );
		}
	}
}
