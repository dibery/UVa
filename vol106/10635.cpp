#include<cstdio>
#include<algorithm>
using namespace std;
int map[ 62501 ], man[ 62500 ], woman[ 62500 ], LIS[ 62500 ];
int LIS_len( int* seq, int len )
{
	int* LIS = new int[ len ], size = 1;
	*LIS = *seq;
	for( int i = 1; i <= len; ++i )
		if( seq[ i ] > LIS[ size-1 ] )
			LIS[ size++ ] = seq[ i ];
		else
			*lower_bound( LIS, LIS+size, seq[ i ] ) = seq[ i ];
	return size;
}

int main()
{
	int T, boy, girl;
	scanf( "%d", &T );

	for( int t = 1; t <= T; ++t )
	{
		scanf( "%*d %d %d", &boy, &girl );
		for( int i = 0; i <= boy; ++i )
			scanf( "%d", man+i ), map[ man[ i ] ] = i;
		for( int i = 0; i <= girl; ++i )
			scanf( "%d", woman+i ), LIS[ i ] = map[ woman[ i ] ];
		printf( "Case %d: %d\n", t, LIS_len( LIS, girl ) );
	}
	return 0;
}