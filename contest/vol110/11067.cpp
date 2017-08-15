#include<cstdio>

int main()
{
	for( int w, h, nw; scanf( "%d %d %d", &w, &h, &nw ) && w; )
	{
		bool wolf[ 101 ][ 101 ] = { { false } };
		int path[ 101 ][ 101 ] = { { 0 } };

		for( int x, y; nw-- && scanf( "%d %d", &x, &y ); wolf[ x ][ y ] = true );
		for( int x = 1; x <= w && !wolf[ x ][ 0 ]; ++x )
			path[ x ][ 0 ] = 1;
		for( int y = 1; y <= h && !wolf[ 0 ][ y ]; ++y )
			path[ 0 ][ y ] = 1;
		for( int x = 1; x <= w; ++x )
			for( int y = 1; y <= h; ++y )
				if( !wolf[ x ][ y ] )
					path[ x ][ y ] = path[ x - 1 ][ y ] + path[ x ][ y - 1 ];
		if( path[ w ][ h ] == 0 )
			puts( "There is no path." );
		else if( path[ w ][ h ] == 1 )
			puts( "There is one path from Little Red Riding Hood's house to her grandmother's house." );
		else
			printf( "There are %d paths from Little Red Riding Hood's house to her grandmother's house.\n", path[ w ][ h ] );
	}
}
