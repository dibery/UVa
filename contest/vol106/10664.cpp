#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, thing[ 20 ];
	char delim;

	for( scanf( "%d", &t ); t--; )
	{
		int pack[ 21 ][ 4001 ] = { 0 }, size = 0, sum = 0;
		while( scanf( "%d%c", thing + size++, &delim ) == 2 && delim == ' ' );
		for( int i = 0; i < size; ++i )
			sum += thing[ i ];
		if( sum % 2 == 0 )
		for( int i = 1; i <= size; ++i )
			for( int j = 1; j <= sum >> 1; ++j )
				if( j < thing[ i-1 ] )
					pack[ i ][ j ] = pack[ i-1 ][ j ];
				else
					pack[ i ][ j ] = max( pack[ i-1 ][ j ], pack[ i-1 ][ j-thing[ i-1 ] ] + thing[ i-1 ] );
		puts( pack[ size ][ sum/2 ] == sum/2? "YES" : "NO" );
	}
}
