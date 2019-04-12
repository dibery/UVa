#include<cstdio>

int main()
{
	long long int catalan[ 26 ] = { 1 }, super[ 27 ] = { 0, 1, 1 };
	int in;

	for( int i = 1; i < 26; ++i )
		for( int j = 0; j < i; ++j )
			catalan[ i ] += catalan[ j ] * catalan[ i-1-j ];
	for( int i = 3; i <= 26; ++i )
		super[ i ] = ( 3 * ( 2*i - 3 ) * super[ i-1 ] - (i-3) * super[ i-2 ] ) / i;

	while( scanf( "%d", &in ) == 1 )
		printf( "%lld\n", super[ in ] - catalan[ in-1 ] );
}
