#include<cstdio>

int main()
{
	int ans[ 10001 ] = { 0 }, n, ok = 0;

	for( int y = 1; y < 100; ++y )
		for( int x = y; x*x*x - y*y*y <= 10000; ++x )
			if( !ans[ x*x*x - y*y*y ] )
				ans[ x*x*x - y*y*y ] = x*100+y, ++ok;
	while( scanf( "%d", &n ) && n )
		printf( ans[ n ]? "%d %d\n" : "No solution\n", ans[ n ] / 100, ans[ n ] % 100 );
}
