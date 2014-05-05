#include<cstdio>
#include<cctype>
bool empty( char board[ 8 ][ 9 ] )
{
	for( int i = 0; i < 8; ++i )
		for( int j = 0; j < 8; ++j )
			if( board[ i ][ j ] != '.' )
				return false;
	return true;
}
inline bool ok( int m ) { return m < 8 && m >= 0; }

int main()
{
	char board[ 8 ][ 9 ];
	int t = 0, dx[] = { 1, 1, -1, -1, 2, 2, -2, -2 }, dy[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

	while( scanf( "%s", *board ) == 1 )
	{
		bool black = false, white = false;
		int attack[ 8 ][ 8 ] = { 0 };
		for( int i = 1; i < 8; ++i )
			scanf( "%s", board[ i ] );
		if( empty( board ) )
			break;
		for( int i = 0; i < 8 && !black && !white; ++i )
			for( int j = 0; j < 8 && !black && !white; ++j )
				if( board[ i ][ j ] == 'n' || board[ i ][ j ] == 'N' )
					for( int k = 0; k < 8; ++k )
						if( ok( i+dx[ k ] ) && ok( j+dy[ k ] ) )
							attack[ i+dx[ k ] ][ j+dy[ k ] ] |= isupper( board[ i ][ j ] )? 1 : 2;
						else;
				else if( board[ i ][ j ] == 'R' || board[ i ][ j ] == 'r' )
				{
					for( int n = j+1; n < 8; ++n )
					{
						attack[ i ][ n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i ][ n ] != '.' )
							break;
					}
					for( int n = j-1; n >= 0; --n )
					{
						attack[ i ][ n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i ][ n ] != '.' )
							break;
					}
					for( int n = i-1; n >= 0; --n )
					{
						attack[ n ][ j ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ n ][ j ] != '.' )
							break;
					}
					for( int n = i+1; n < 8; ++n )
					{
						attack[ n ][ j ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ n ][ j ] != '.' )
							break;
					}
				}
				else if( board[ i ][ j ] == 'B' || board[ i ][ j ] == 'b' )
				{
					for( int n = 1; n <= i && n <= j; ++n )
					{
						attack[ i-n ][ j-n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i-n ][ j-n ] != '.' )
							break;
					}
					for( int n = 1; n <= i && j+n < 8; ++n )
					{
						attack[ i-n ][ j+n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i-n ][ j+n ] != '.' )
							break;
					}
					for( int n = 1; i+n < 8 && j+n < 8; ++n )
					{
						attack[ i+n ][ j+n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i+n ][ j+n ] != '.' )
							break;
					}
					for( int n = 1; i+n < 8 && n <= j; ++n )
					{
						attack[ i+n ][ j-n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i+n ][ j-n ] != '.' )
							break;
					}
				}
				else if( board[ i ][ j ] == 'Q' || board[ i ][ j ] == 'q' )
				{
					for( int n = j+1; n < 8; ++n )
					{
						attack[ i ][ n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i ][ n ] != '.' )
							break;
					}
					for( int n = j-1; n >= 0; --n )
					{
						attack[ i ][ n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i ][ n ] != '.' )
							break;
					}
					for( int n = i-1; n >= 0; --n )
					{
						attack[ n ][ j ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ n ][ j ] != '.' )
							break;
					}
					for( int n = i+1; n < 8; ++n )
					{
						attack[ n ][ j ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ n ][ j ] != '.' )
							break;
					}
					for( int n = 1; n <= i && n <= j; ++n )
					{
						attack[ i-n ][ j-n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i-n ][ j-n ] != '.' )
							break;
					}
					for( int n = 1; n <= i && j+n < 8; ++n )
					{
						attack[ i-n ][ j+n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i-n ][ j+n ] != '.' )
							break;
					}
					for( int n = 1; i+n < 8 && j+n < 8; ++n )
					{
						attack[ i+n ][ j+n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i+n ][ j+n ] != '.' )
							break;
					}
					for( int n = 1; i+n < 8 && n <= j; ++n )
					{
						attack[ i+n ][ j-n ] |= isupper( board[ i ][ j ] )? 1 : 2;
						if( board[ i+n ][ j-n ] != '.' )
							break;
					}
				}
				else if( board[ i ][ j ] == 'P' && i )
					if( j == 0 )
						attack[ i-1 ][ j+1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
					else if( j == 7 )
						attack[ i-1 ][ j-1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
					else
						attack[ i-1 ][ j-1 ] |= isupper( board[ i ][ j ] )? 1 : 2, attack[ i-1 ][ j+1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
				else if( board[ i ][ j ] == 'p' && i < 7 )
					if( j == 0 )
						attack[ i+1 ][ j+1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
					else if( j == 7 )
						attack[ i+1 ][ j-1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
					else
						attack[ i+1 ][ j-1 ] |= isupper( board[ i ][ j ] )? 1 : 2, attack[ i+1 ][ j+1 ] |= isupper( board[ i ][ j ] )? 1 : 2;
//		for( int i = 0; i < 8 && !black && !white; ++i )
//		 for( int j = 0; j < 8 && !black && !white; ++j );
//			 printf( "%d%s", attack[ i ][ j ], j == 7? "\n" : "" );
		for( int i = 0; i < 8 && !black && !white; ++i )
		 for( int j = 0; j < 8 && !black && !white; ++j )
			 if( board[ i ][ j ] == 'k' && ( attack[ i ][ j ] == 1 || attack[ i ][ j ] == 3 ) )
				 black = true;
			 else if( board[ i ][ j ] == 'K' && attack[ i ][ j ] >= 2 )
				 white = true;
		printf( "Game #%d: %s king is in check.\n", ++t, black? "black" : white? "white" : "no" );
	}
}
