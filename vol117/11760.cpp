#include<cstdio>

int main()
{
	for( int t = 0, r, c, n, R, C; scanf( "%d %d %d", &r, &c, &n ) && r; )
	{
		bool row[ 10000 ] = { false }, col[ 10000 ] = { false }, escape = false;
		
		for( int r, c; n-- && scanf( "%d %d", &r, &c ); )
			row[ r ] = col[ c ] = true;
		scanf( "%d %d", &R, &C );
		for( int i = R - 1; i <= R + 1; ++i )
			for( int j = C - 1; j <= C + 1; ++j )
				if( ( i == R || j == C ) && i >= 0 && i < r && j >= 0 && j < c && !row[ i ] && !col[ j ] )
					escape = true;
		printf( "Case %d: %s\n", ++t, escape? "Escaped again! More 2D grid problems!" : "Party time! Let's find a restaurant!" );
	}
}
