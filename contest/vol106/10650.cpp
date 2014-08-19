#include<cstdio>
#include<algorithm>
const int N = 32003;
bool isprime[ N+1 ] = { false, false, true };
int prime[ 3500 ] = { 2 }, size = 1;

bool check( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	int begin, end;

	for( int i = 3; i <= N; i += 2 )
		if( check( i ) )
			isprime[ i ] = true, prime[ size++ ] = i;

	while( scanf( "%d %d", &begin, &end ) && begin+end )
	{
		if( begin > end )
			std::swap( begin, end );
		for( int i = std::lower_bound( prime, prime+size, begin ) - prime; prime[ i ] <= end && i < size; ++i )
		{
			int t = i;
			if( prime[ i+1 ] - prime[ i ] == prime[ i+2 ] - prime[ i+1 ] && prime[ i+1 ] - prime[ i ] != prime[ i ] - prime[ i-1 ] )
				for( t = i+2; prime[ t ] - prime[ t-1 ] == prime[ i+1 ] - prime[ i ] && t < size; ++t );
			if( prime[ t-1 ] <= end )
				for( int n = i; n < t; ++n )
					printf( "%d%s", prime[ n ], n == t-1? "\n" : " " );
		}
	}
}
