#include<cstdio>
#include<cstring>

long long int ans[ 33 ][ 33 ][ 100 ];
bool vis[ 33 ][ 33 ][ 100 ];
int mod[ 64 ] = { 1 }, len, mul, t;

long long int get( int one, int zero, int res, int done )
{
	if( vis[ one ][ zero ][ res ] )
		return ans[ one ][ zero ][ res ];
	vis[ one ][ zero ][ res ] = true;
	if( one )
		ans[ one ][ zero ][ res ] += get( one-1, zero, ( mul + res - mod[ len-done-1 ] ) % mul, done+1 );
	if( zero )
		ans[ one ][ zero ][ res ] += get( one, zero-1, res, done+1 );
	if( one + zero == 0 )
		ans[ one ][ zero ][ res ] = res == 0;
	return ans[ one ][ zero ][ res ];
}

int main()
{
	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		memset( ans, 0, sizeof( ans ) );
		memset( vis, false, sizeof( vis ) );

		scanf( "%d %d", &len, &mul );
		if( mul )
			for( int i = 1; i < len; ++i )
				mod[ i ] = mod[ i-1 ] * 2 % mul;
		if( len % 2 == 0 && mul )
			*ans[ len/2 ][ len/2 ] = get( len / 2 - 1, len / 2, ( mul - mod[ len-1 ] ) % mul, 1 );

		printf( "Case %d: %lld\n", n, ans[ len / 2 ][ len / 2 ][ 0 ] );
	}
}
