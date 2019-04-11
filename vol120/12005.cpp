#include<cstdio>

long long int prime[ 1280000 ] = { 2 }, size = 1;
bool notp[ 20000001 ] = { true, true };

int factor( long long int n )
{
	int ans = 1;

	for( int i = 0; i < size && prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
		{
			int tmp = 0;
			while( n % prime[ i ] == 0 )
				n /= prime[ i ], ++tmp;
			ans *= tmp + 1;
		}
	if( n != 1 )
		ans *= 2;
	return ans;
}

int main()
{
	for( int i = 4; i < 20000001; i += 2 )
		notp[ i ] = true;
	for( int i = 3; i*i < 20000001; i += 2 )
		if( !notp[ i ] )
			for( int j = i*i; j < 20000001; j += 2*i )
				notp[ j ] = true;
	for( int i = 3; i < 20000001; i += 2 )
		if( !notp[ i ] )
			prime[ size++ ] = i;

	long long int in;

	while( scanf( "%lld", &in ) && in )
		printf( "%lld %d\n", in, factor( 4*in - 3 ) );
}
