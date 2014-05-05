#include<cstdio>
#include<cstring>
#include<algorithm>
const unsigned int MOD = 34943;

int main()
{
	char str[ 1025 ];
	unsigned int mod[ 1025 ] = { 65536 % MOD };

	for( int i = 1; i <= 1024; ++i )
		mod[ i ] = mod[ i-1 ] * 256 % MOD;

	while( gets( str ) && strcmp( str, "#" ) )
	{
		unsigned int r = 0;
		std::reverse( str, str + strlen( str ) );
		for( int i = 0; str[ i ]; ++i )
			r += str[ i ] * mod[ i ],
		r %= MOD;
		if( !r )
			puts( "00 00" );
		else
			printf( "%02X %02X\n", ( MOD - r ) / 256, ( MOD - r ) % 256 );
	}
}