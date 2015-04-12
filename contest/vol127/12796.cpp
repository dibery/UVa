#include<bits/stdc++.h>
using namespace std;
const int N = 100;

void mul( int a[ N ][ N ], int b[ N ][ N ], int c[ N ][ N ], int size ) // a = b*c
{
	int tmp[ N ][ N ] = { { 0 } };

	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			for( int k = 0; k < size; ++k )
				( tmp[ i ][ j ] = ( tmp[ i ][ j ] + b[ i ][ k ] * c[ k ][ j ] ) ) %= 10000;
	transform( *tmp, tmp[ size ], *a, [] ( int n ) { return n % 10000; } );
}

void pow( int a[ N ][ N ], int b[ N ][ N ], int exp, int size ) // a * b^e
{
	int base[ 30 ][ N ][ N ] = { { { 0 } } };

	copy( b[ 0 ], b[ size ], base[ 0 ][ 0 ] );
	for( int i = 1; i < 30; ++i )
		mul( base[ i ], base[ i-1 ], base[ i-1 ], size );
	for( int i = 0; i < 30; ++i )
		if( exp & 1 << i )
			mul( a, a, base[ i ], size );
}

int main()
{
	int stop, dist, begin, end, n;
	
	while( scanf( "%d %d %d %d", &stop, &dist, &begin, &end ) == 4 )
	{
		int mat[ N ][ N ] = { { 0 } }, way[ N ][ N ] = { { 0 } };

		--begin, --end;
		way[ begin ][ begin ] = 1;
		for( int i = 0; i < stop; ++i )
			for( int j = 0; j < 4; ++j )
				scanf( "%d", &n ), ++mat[ i ][ n-1 ];

		pow( way, mat, dist, stop );
		printf( "%d\n", way[ begin ][ end ] );
	}
}
