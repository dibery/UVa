#include<cstdio>
#include<cstring>
#define ALL ((1<<man)-1)

bool ok[ 1 << 16 ][ 100 ], vis[ 1 << 16 ][ 100 ];
int sum[ 1 << 16 ], need[ 15 ], man, l, w, t;

bool split( int served = 0, int side = l )
{
	int& s = served;
	int x = side, y = sum[ ALL ^ s ] / x;
	if( vis[ s ][ side ] )
		return ok[ s ][ side ];
	if( ( served | ~s & -~s ) == ALL )
		return ok[ served ][ x ] = ok[ served ][ y ] = true;
	vis[ s ][ x ] = vis[ s ][ y ] = true;
	for( int i = ~s & -~s | s; i < ALL; i = i+1 | s )
		if( sum[ i ^ s ] % y == 0 && split( i, y ) && split( ALL ^ i | s, y ) ||
				sum[ i ^ s ] % x == 0 && split( i, x ) && split( ALL ^ i | s, x ) )
			return ok[ s ][ x ] = ok[ s ][ y ] = true;
	return false;
}

int main()
{
	while( scanf( "%d", &man ) && man )
	{
		memset( ok, false, sizeof( ok ) );
		memset( vis, false, sizeof( vis ) );
		memset( sum, 0, sizeof( sum ) );
		scanf( "%d %d", &l, &w );
		for( int i = 0; i < man; ++i )
			scanf( "%d", need+i );
		for( int i = 1; i <= ALL; ++i )
			for( int j = 0; j < man; ++j )
				if( i & 1 << j )
					sum[ i ] += need[ j ];
		printf( "Case %d: %s\n", ++t, sum[ ALL ] == l*w && split()? "Yes" : "No" );
	}
}
