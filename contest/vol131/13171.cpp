#include<cstdio>

int main()
{
	int t, m, y, c;
	char draw[ 100001 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %d %d %s", &m, &y, &c, draw ); )
	{
		for( int i = 0; draw[ i ]; ++i )
			if( draw[ i ] == 'M' )
				--m;
			else if( draw[ i ] == 'Y' )
				--y;
			else if( draw[ i ] == 'C' )
				--c;
			else if( draw[ i ] == 'R' )
				--m, --y;
			else if( draw[ i ] == 'V' )
				--m, --c;
			else if( draw[ i ] == 'G' )
				--y, --c;
			else if( draw[ i ] == 'B' )
				--m, --c, --y;
		if( m < 0 || y < 0 || c < 0 )
			puts( "NO" );
		else
			printf( "YES %d %d %d\n", m, y, c );
	}
}
