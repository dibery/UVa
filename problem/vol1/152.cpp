#include<cstdio>
#include<cmath>
#include<algorithm>
inline int sq( int a ) { return a*a; }

int main()
{
	int x[ 5001 ], y[ 5001 ], z[ 5001 ], total = 0, ans[ 10 ] = { 0 };

	while( scanf( "%d %d %d", x+total, y+total, z+total ) && ( x[ total ] + y[ total ] + z[ total ] ) )
		++total;
	for( int i = 0; i < total; ++i )
	{
		int min = 300;
		for( int j = 0; j < total; ++j )
			if( i != j )
				min = std::min( min, sq( x[ i ] - x[ j ] ) + sq( y[ i ] - y[ j ] ) + sq( z[ i ] - z[ j ] ) );
		if( min < 100 )
			++ans[ int( sqrt( double( min ) ) ) ];
	}
	for( int i = 0; i < 10; ++i )
		printf( "%4d", ans[ i ] );
	printf( "\n" );

	return 0;
}
