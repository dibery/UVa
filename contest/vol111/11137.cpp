#include<cstdio>
#include<algorithm>
long long int way[ 10000 ][ 22 ];

int main()
{
	int n;
	std::fill( way[ 0 ], way[ 0 ] + 22, 1 );
	for( int i = 1; i < 10000; ++i )
		for( int j = 1; j <= 21; ++j )
			if( i >= j*j*j )
				way[ i ][ j ] = way[ i - j*j*j ][ j ] + way[ i ][ j-1 ];
			else
				way[ i ][ j ] = way[ i ][ j-1 ];
	while( scanf( "%d", &n ) == 1 )
		printf( "%lld\n", way[ n ][ 21 ] );
}
