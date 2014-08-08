#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
int prime[ 4800 ] = { 2, 3, 5 }, size = 3, tmp[ 1000000 ];
bool isprime( int n )
{
	for( int i = 1; prime[ i ] * prime[ i ] <= n && i < size; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 7; i <= 46341; i += 2 )
		if( isprime( i ) )
			prime[ size++ ] = i;
	int begin, end;

	while( scanf( "%d %d", &begin, &end ) == 2 )
	{
		int ts = 0, near = INT_MAX, far = INT_MIN, N, F;
		begin = max( 2, begin );
		if( begin == 2 )
			tmp[ ts++ ] = 2;
		for( long long int i = begin + ( begin % 2 == 0 ); i <= end; i += 2 )
			if( isprime( i ) )
				tmp[ ts++ ] = i;
		for( int i = 1; i < ts; ++i )
		{
			if( tmp[ i ] - tmp[ i-1 ] > far )
				far = tmp[ i ] - tmp[ i-1 ], F = i;
			if( tmp[ i ] - tmp[ i-1 ] < near )
				near = tmp[ i ] - tmp[ i-1 ], N = i;
		}
		if( far != INT_MIN )
			printf( "%d,%d are closest, %d,%d are most distant.\n", tmp[ N-1 ], tmp[ N ], tmp[ F-1 ], tmp[ F ] );
		else
			puts( "There are no adjacent primes." );
	}
}
