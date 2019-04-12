#include<cstdio>
const int N = 205;

int main()
{
	for( int city, route, start, end, day; scanf( "%d %d", &city, &route ) && city; )
	{
		bool adj[ N ][ N ] = { { false } }, vis[ N ][ N ] = { { false } };

		for( int a, b; route-- && scanf( "%d %d", &a, &b ); )
			adj[ a - 1 ][ b - 1 ] = adj[ b - 1 ][ a - 1 ] = 1;
		scanf( "%d %d %d", &start, &end, &day );

		vis[ 0 ][ start - 1 ] = true;
		for( int i = 0; i < day; ++i )
			for( int j = 0; j < city; ++j )
				if( vis[ i ][ j ] )
					for( int k = 0; k < city; ++k )
						vis[ i + 1 ][ k ] |= adj[ j ][ k ];

		puts( vis[ day ][ end - 1 ]? "Yes, Teobaldo can travel." : "No, Teobaldo can not travel." );
	}
}
