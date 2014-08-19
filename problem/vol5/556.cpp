#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

enum way{ E, S, W, N };
char wall = '1';

int main()
{
	int h, w, i, j;

	while( scanf( "%d %d\n", &h, &w ) && h+w )
	{
		char maze[ h+2 ][ w+2 ];
		int vis[ h+2 ][ w+2 ], time[ 5 ] = { 0 };
		way dir = E;
		memset( vis, 0, sizeof( vis ) );
		memset( maze, '1', sizeof( maze ) );

		for( int i = 1; i <= h; ++i, getchar() )
			for( int j = 1; j <= w; ++j )
				scanf( "%c", &maze[ i ][ j ] );
		i = h, j = 1;

		do
		{
			++vis[ i ][ j ];
			if( dir == E )
				if( maze[ i+1 ][ j ] != wall )
					dir = S, ++i;
				else if( maze[ i ][ j+1 ] != wall )
					++j;
				else if( maze[ i-1 ][ j ] != wall )
					dir = N, --i;
				else
					dir = W, --j;
			else if( dir == S )
				if( maze[ i ][ j-1 ] != wall )
					dir = W, --j;
				else if( maze[ i+1 ][ j ] != wall )
					++i;
				else if( maze[ i ][ j-1 ] != wall )
					dir = E, --j;
				else
					dir = N, --i;
			else if( dir == W )
				if( maze[ i-1 ][ j ] != wall )
					dir = N, --i;
				else if( maze[ i ][ j-1 ] != wall )
					--j;
				else if( maze[ i+1 ][ j ] != wall )
					dir = S, ++i;
				else
					dir = E, ++j;
			else// if( dir == N )
				if( maze[ i ][ j+1 ] != wall )
					dir = E, ++j;
				else if( maze[ i-1 ][ j ] != wall )
					--i;
				else if( maze[ i ][ j-1 ] != wall )
					dir = W, --j;
				else
					dir = S, ++i;
		}
		while( i != h || j != 1 );
		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( maze[ i ][ j ] != wall )
					++time[ min( vis[ i ][ j ], 4 ) ];
		for( int i = 0; i < 5; ++i )
			printf( "%3d", time[ i ] );
		puts("");
	}
}
