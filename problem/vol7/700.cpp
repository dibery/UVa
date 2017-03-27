#include<cstdio>

int main()
{
	for( int t = 1, computer; scanf( "%d", &computer ) && computer; ++t )
	{
		int stat[ 10000 ] = { 0 }, disp, a, b, ans = -1;

		for( int i = 0; i < computer && scanf( "%d %d %d", &disp, &a, &b ); ++i )
			for( int y = disp; y < 10000; y += b - a )
				stat[ y ] |= 1 << i;
		for( int y = 0; ans == -1 && y < 10000; ++y )
			if( stat[ y ] == ( 1 << computer ) - 1 )
				ans = y;
		printf( "Case #%d:\n", t );
		if( ans == -1 )
			puts( "Unknown bugs detected.\n" );
		else
			printf( "The actual year is %d.\n\n", ans );
	}
}
