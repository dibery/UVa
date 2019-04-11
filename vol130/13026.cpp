#include<cstdio>

bool ok( char* a, char* b )
{
	int diff = 0;
	for( ; *a; ++a, ++b )
		diff += *a != *b;
	return diff <= 1;
}

int main()
{
	char dad[ 1000 ][ 12 ] = { { 0 } }, mom[ 12 ];
	int t, n;

	scanf( "%d", &t );
	for( int N = 1; N <= t; ++N )
	{
		scanf( "%d\n", &n );
		for( int i = 0; i < n; ++i )
			gets( dad[ i ] );
		gets( mom );

		printf( "Case %d:\n", N );
		for( int i = 0; i < n; ++i )
			if( ok( mom, dad[ i ] ) )
				puts( dad[ i ] );
	}
}
