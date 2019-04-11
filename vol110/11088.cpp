#include<cstdio>
#include<algorithm>

int bit1( int n )
{
	int b = 0;
	while( n )
		b += n & 1, n >>= 1;
	return b;
}

int find( int all, int now, int val[], bool vis[], int sum[], int bit3[] )
{
	if( vis[ now ] )
		return val[ now ];
	vis[ now ] = true;

	for( int i = 0; i < 455 && bit3[ i ] < ( 1 << all ); ++i )
		if( ( bit3[ i ] & now ) == 0 )
			val[ now ] = std::max( val[ now ], ( sum[ bit3[ i ] ] >= 20 ) + find( all, now | bit3[ i ], val, vis, sum, bit3 ) );
	return val[ now ];
}

int main()
{
	int size = 0, n[ 15 ], t = 0, bit3[ 455 ] = { 0 };
	for( int i = 0; i < 32768; ++i )
		if( bit1( i ) == 3 )
			bit3[ size++ ] = i;

	while( scanf( "%d", &size ) && size )
	{
		bool vis[ 32768 ] = { false };
		int val[ 32768 ] = { 0 }, sum[ 32768 ] = { 0 };
		for( int i = 0; i < size; ++i )
			scanf( "%d", n+i ), sum[ 1 << i ] = n[ i ];
		for( int i = 1; i < ( 1 << size ); ++i )
			if( i & i-1 )
				sum[ i ] = sum[ i & -i ] + sum[ i & ~( i & -i ) ];
		find( size, 0, val, vis, sum, bit3 );
		printf( "Case %d: %d\n", ++t, *val );
	}
}
