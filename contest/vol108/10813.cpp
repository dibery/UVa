#include<cstdio>

bool bingo( bool brd[ 5 ][ 5 ] )
{
	int up = 0, down = 0;
	for( int i = 0; i < 5; ++i )
	{
		int hor = 0, ver = 0;
		for( int j = 0; j < 5; ++j )
			hor += brd[ i ][ j ], ver += brd[ j ][ i ];
		down += brd[ i ][ i ], up += brd[ 4-i ][ i ];
		if( hor == 5 || ver == 5 || down == 5 || up == 5 )
			return true;
	}
	return false;
}

int main()
{
	int t, brd[ 5 ][ 5 ], seq[ 75 ], ans;

	for( scanf( "%d", &t ); t; --t )
	{
		bool check[ 5 ][ 5 ] = { false };
		check[ 2 ][ 2 ] = true;

		for( int i = 0; i < 5; ++i )
			for( int j = 0; j < 5; ++j )
				if( i != 2 || j != 2 )
					scanf( "%d", &brd[ i ][ j ] );
		for( int i = 0; i < 75; ++i )
			scanf( "%d", seq+i );
		for( ans = 0; !bingo( check ); ++ans )
			for( int i = 0; i < 5; ++i )
				for( int j = 0; j < 5; ++j )
					if( brd[ i ][ j ] == seq[ ans ] )
						check[ i ][ j ] = true;
		printf( "BINGO after %d numbers announced\n", ans );
	}
}
