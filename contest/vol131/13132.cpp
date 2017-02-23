#include<cstdio>
#include<cmath>
#include<cfloat>

const int N = 1000001;
int primes[ 305 ] = { 2 }, size = 1;
long long phi[ N ] = { 0, 1 };

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i * i <= N; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;

	for( int i = 2; i < N; ++i )
	{
		phi[ i ] = i;
		for( int j = 0; primes[ j ] * primes[ j ] <= i && j < size; ++j )
			if( i % primes[ j ] == 0 )
			{
				int t = i;
				while( t % primes[ j ] == 0 )
					t /= primes[ j ];
				phi[ i ] = phi[ i ] / primes[ j ] * ( primes[ j ] - 1 );
				if( t > 1 )
					phi[ i ] = phi[ i ] * phi[ t ] / t;
				break;
			}
		phi[ i ] -= phi[ i ] == i;
	}

	int t, n;
	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); printf( "%lld\n", phi[ n ] ) );
}
