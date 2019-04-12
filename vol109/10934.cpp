#include<cstdio>
#include<algorithm>

int main()
{
	long long int way[ 101 ][ 64 ] = { { 0 } }, story;
	int ballon, n;

	for( int i = 1; i <= 100; ++i )
		for( int j = 1; j < 64; ++j )
			way[ i ][ j ] = way[ i-1 ][ j-1 ] + way[ i ][ j-1 ] + 1;

	while( scanf( "%d %lld", &ballon, &story ) && ballon )
		if( ( n = std::lower_bound( way[ ballon ], way[ ballon ] + 64, story ) - way[ ballon ] ) == 64 )
			puts( "More than 63 trials needed." );
		else
			printf( "%d\n", n );
}
