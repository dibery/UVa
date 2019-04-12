#include<cstdio>
#include<cctype>
#include<algorithm>
using namespace std;

int main()
{
	int size, t = 0;
	char in[ 30000 ];
	
	while( scanf( "%d%*c", &size ) && size )
	{
		char buffer[ 10 ][ 20 ] = { { 0 } };
		int h = 0, w = 0;
		bool overwrite = true;
		
		for( int i = 0; i < 10; ++i )
			for( int j = 0; j < 10; ++j )
				buffer[ i ][ j ] = ' ';
		for( int k = 0; k < size; ++k )
		{
			gets( in );
		
		for( int i = 0; in[ i ]; ++i )
		{
			if( in[ i ] != '^' ) //normal char
				if( overwrite )
				{
					if( w < 10 )
						buffer[ h ][ w++ ] = in[ i ];
					else if( w == 10 )
						buffer[ h ][ 9 ] = in[ i ];
					if( w == 10 ) w = 9;
				}
				else
				{
					if( w < 10 )
					{
						for( int i = 9; i > w; --i )
							buffer[ h ][ i ] = buffer[ h ][ i-1 ];
						buffer[ h ][ w++ ] = in[ i ];
						if( w == 10 ) w = 9;
					}
					else if( w == 10 )
						buffer[ h ][ 9 ] = in[ i ];
				}
			else // ^
			{
				++i;
				if( in[ i ] == 'b' )
					w = 0;
				else if( in[ i ] == 'c' )
					for( int i = 0; i < 10; ++i )
						for( int j = 0; j < 10; ++j )
							buffer[ i ][ j ] = ' ';
				else if( in[ i ] == 'd' )
					h = min( 9, h+1 );
				else if( in[ i ] == 'e' )
					for( int i = overwrite? w : w; i < 10; ++i )
						buffer[ h ][ i ] = ' ';
				else if( in[ i ] == 'h' )
					h = w = 0;
				else if( in[ i ] == 'i' )
					overwrite = false;
				else if( in[ i ] == 'l' )
					w = w? w-1 : 0;
				else if( in[ i ] == 'o' )
					overwrite = true;
				else if( in[ i ] == 'r' )
					w = min( 9, w+1 );
				else if( in[ i ] == 'u' )
					h = max( 0, h-1 );
				else if( in[ i ] == '^' )
					if( overwrite )
					{
						if( w < 10 )
							buffer[ h ][ w++ ] = in[ i ];
						else if( w == 10 )
							buffer[ h ][ 9 ] = in[ i ];
						if( w == 10 ) w = 9;
					}
					else
					{
						if( w < 10 )
						{
							for( int i = 9; i > w; --i )
								buffer[ h ][ i ] = buffer[ h ][ i-1 ];
							buffer[ h ][ w++ ] = in[ i ];
							if( w == 10 ) w = 9;
						}
						else if( w == 10 )
							buffer[ h ][ 9 ] = in[ i ];
					}
				else if( isdigit( in[ i ] ) )
				{
					h = in[ i ] - '0';
					++i;
					w = in[ i ] - '0';
				}
			}
		}
		}
		
		printf( "Case %d\n", ++t );
		puts( "+----------+" );
		for( int i = 0; i < 10; ++i )
		{
			putchar( '|' );
			printf( buffer[ i ] );
			putchar( '|' );
			puts( "" );
		}
		puts( "+----------+" );
	}
}
		
