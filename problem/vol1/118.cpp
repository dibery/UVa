#include<cstdio>
#include<cstring>

int main()
{
	int sizex, sizey, x, y, way;
	char tmp, table[] = { "NESW" }, cmd[ 100 ];
	bool scent[ 51 ][ 51 ] = { false };
	scanf( "%d %d", &sizex, &sizey );

	while( scanf( "%d %d %c %s", &x, &y, &tmp, cmd ) != EOF )
	{
		bool out = false;
		way = strchr( table, tmp ) - table;

		for( int i = 0; cmd[ i ]; ++i )
		{
			int lastx = x, lasty = y;
			if( cmd[ i ] == 'R' )
				way = ( way+1 ) % 4;
			else if( cmd[ i ] == 'L' )
				way = ( way+3 ) % 4;
			else//
				if( way == 0 )
					++y;
				else if( way == 1 )
					++x;
				else if( way == 2 )
					--y;
				else
					--x;
			if( x < 0 || x > sizex || y < 0 || y > sizey )
			{
				x = lastx, y = lasty;
				if( !scent[ lastx ][ lasty ] )
				{
					out = scent[ lastx ][ lasty ] = true;
					break;
				}
			}
		}
		printf( "%d %d %c%s\n", x, y, table[ way ], out? " LOST" : "" );
	}

	return 0;
}