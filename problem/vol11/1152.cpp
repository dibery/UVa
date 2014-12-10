#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, s, n[ 4 ][ 4000 ], *sum = new int[ 16000000 ], size;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &s );
		for( int i = size = 0; i < s; ++i )
			for( int j = 0; j < 4; ++j )
				scanf( "%d", n[ j ]+i );
		for( int i = 0; i < s; ++i )
			for( int j = 0; j < s; ++j )
				sum[ size++ ] = n[ 0 ][ i ] + n[ 1 ][ j ];
		sort( sum, sum+size );
		long long int ans = 0;
		for( int i = 0; i < s; ++i )
			for( int j = 0; j < s; ++j )
				ans += upper_bound( sum, sum+size, -n[ 2 ][ i ] - n[ 3 ][ j ] ) - lower_bound( sum, sum+size, -n[ 2 ][ i ] - n[ 3 ][ j ] );
		printf( "%lld\n%s", ans, t? "\n" : "" );
	}
}
