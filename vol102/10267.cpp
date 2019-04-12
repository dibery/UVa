#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int x, y, x1, y1, x2, y2;
char name[ 500 ] = { 0 }, brd[ 250 ][ 250 ] = { { 0 } }, cmd, color;

void dfs( int X, int Y, char old, char New )
{
	brd[ X ][ Y ] = New;
	for( int i = X-1; i <= X+1; ++i )
		for( int j = Y-1; j <= Y+1; ++j )
			if( i >= 0 && i < x && j >= 0 && j < y && i == X ^ j == Y && brd[ i ][ j ] == old )
				dfs( i, j, old, New );
}

int main()
{
	for( ; scanf( "%c", &cmd ) == 1 && cmd != 'X'; gets( name ) )
		if( cmd == 'I' )
		{
			memset( brd, 'O', sizeof( brd ) );
			scanf( "%d %d", &y, &x );
		}
		else if( cmd == 'C' )
			memset( brd, 'O', sizeof( brd ) );
		else if( cmd == 'L' )
		{
			scanf( "%d %d ", &x1, &y1 );
			scanf( "%c", brd[ --y1 ] + --x1 );
		}
		else if( cmd == 'V' )
		{
			scanf( "%d %d %d %c", &y1, &x1, &x2, &color );
			if( x1 > x2 )
				swap( x1, x2 );
			--y1, --x1, --x2;
			for( int i = x1; i <= x2; ++i )
				brd[ i ][ y1 ] = color;
		}
		else if( cmd == 'H' )
		{
			scanf( "%d %d %d %c", &y1, &y2, &x1, &color );
			if( y1 > y2 )
				swap( y1, y2 );
			--y1, --y2, --x1;
			for( int i = y1; i <= y2; ++i )
				brd[ x1 ][ i ] = color;
		}
		else if( cmd == 'K' )
		{
			scanf( "%d %d %d %d %c", &x1, &y1, &x2, &y2, &color );
			if( x1 > x2 )
				swap( x1, x2 );
			if( y1 > y2 )
				swap( y1, y2 );
			--x1, --x2, --y1, --y2;
			for( int i = x1; i <= x2; ++i )
				for( int j = y1; j <= y2; ++j )
					brd[ j ][ i ] = color;
		}
		else if( cmd == 'F' )
		{
			scanf( "%d %d %c", &x1, &y1, &color );
			--x1, --y1;
			if( color != brd[ y1 ][ x1 ] )
				dfs( y1, x1, brd[ y1 ][ x1 ], color );
		}
		else if( cmd == 'S' )
		{
			scanf( "%s", name );
			puts( name );
			for( int i = 0; i < x; ++i, puts( "" ) )
				for( int j = 0; j < y; ++j )
					putchar( brd[ i ][ j ] );
		}
}
