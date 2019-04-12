#include<cstdio>
int way[ 1121 ][ 16 ][ 188 ], primes[ 300 ] = { 2 }, size = 1, sum, item;

bool isprime( int n )
{
	for( int i = 3; i * i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < 1120; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;
	for( int i = 0; i <= size; ++i )
		way[ 0 ][ 0 ][ i ] = 1;
	for( int i = 2; i <= 1120; ++i )
		for( int j = 1; j <= 14; ++j )
			for( int k = size - 1; k >= 0; --k )
				if( i >= primes[ k ] )
					way[ i ][ j ][ k ] = way[ i ][ j ][ k+1 ] + way[ i - primes[ k ] ][ j-1 ][ k+1 ];
	while( scanf( "%d %d", &sum, &item ) && sum )
		printf( "%d\n", *way[ sum ][ item ] );
}
