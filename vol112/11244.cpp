#include<cstdio>

int main()
{
	for( int h, w; scanf( "%d %d", &h, &w ) && h; )
	{
		char sky[ 110 ][ 110 ] = { { 0 } };
		int star = 0;

		for( int i = 1; i <= h; ++i )
			scanf( "%s", sky[ i ] + 1 );
		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( sky[ i ][ j ] == '*' )
				{
					bool ok = true;
					for( int m = i-1; m <= i+1; ++m )
						for( int n = j-1; n <= j+1; ++n )
							if( m != i || n != j )
								ok &= sky[ m ][ n ] != '*';
					star += ok;
				}
		printf( "%d\n", star );
	}
}
