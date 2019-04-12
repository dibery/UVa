#include<cstdio>

int ans[ 100001 ], n, t;

int sum( int n )
{
	int r = 0;
	while( n )
		r += n % 10, n /= 10;
	return r;
}

int main()
{
	for( int i = 1; i <= 100000; ++i )
		if( ans[ i + sum( i ) ] == 0 )
			ans[ i + sum( i ) ] = i;
	for( scanf( "%d", &t ); t; --t )
		scanf( "%d", &n ), printf( "%d\n", ans[ n ] );
}
