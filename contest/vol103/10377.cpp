#include<cstdio>
#include<cstring>
#include<iostream>

int main()
{
	int sizex, sizey, x, y, way, t;
	char tmp, table[] = { "NESW" }, trash[ 100 ] = { 0 };

	for( scanf( "%d", &t ); t--; printf( t? "\n" : "" ) )
	{
		char field[ 62 ][ 62 ] = { 0 };
		way = 0;
		scanf( "%d %d\n", &sizex, &sizey );
		for( int i = 1; i <= sizex; ++i )
			gets( field[ i ] + 1 );
		scanf( "%d %d", &x, &y );

		while( ( tmp = getchar() ) != 'Q' )
		{
			if( tmp == 'R' )
				way = ( way+1 ) % 4;
			else if( tmp == 'L' )
				way = ( way+3 ) % 4;
			else if( tmp == 'F' )
				if( way == 1 && field[ x ][ y+1 ] == ' ' )
					++y;
				else if( way == 2 && field[ x+1 ][ y ] == ' ' )
					++x;
				else if( way == 3 && field[ x ][ y-1 ] == ' ' )
					--y;
				else if( way == 0 && field[ x-1 ][ y ] == ' ' )
					--x;
		}
		printf( "%d %d %c\n", x, y, table[ way ] );
	}

	return 0;
}
