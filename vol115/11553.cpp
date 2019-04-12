#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
	int order[] = { 0, 1, 2, 3, 4, 5, 6, 7 }, n[ 8 ][ 8 ], size;

	for( scanf( "%*d" ); scanf( "%d", &size ) == 1; sort( order, order + 8 ) )
	{
		int ans = INT_MAX;
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%d", n[ i ] + j );
		do
		{
			int tmp = 0;
			for( int i = 0; i < size; ++i )
				tmp += n[ i ][ order[ i ] ];
			ans = min( ans, tmp );
		} while( next_permutation( order, order + size ) );
		printf( "%d\n", ans );
	}
}
