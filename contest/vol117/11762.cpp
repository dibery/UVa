#include<cstdio>

int prime[ 90000 ] = { 2 }, size = 1;
double ans[ 1000001 ];

int isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

double solve( int n )
{
	if( ans[ n ] )
		return ans[ n ];
	if( n == 1 )
		return 0;
	int pos = 0;
	double calc = 0, tmp = 0;
	for( pos = 0; prime[ pos ] <= n && pos < size; ++pos )
		if( n % prime[ pos ] )
			++calc;
		else
			tmp += solve( n / prime[ pos ] );
	return ans[ n ] = ( tmp + pos ) / ( pos - calc );
}

int main()
{
	for( int i = 3; i < 1000000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	int t, n;

	scanf( "%d", &t );
	for( int q = 1; q <= t; ++q )
	{
		scanf( "%d", &n );
		printf( "Case %d: %.10f\n", q, solve( n ) );
	}
}
