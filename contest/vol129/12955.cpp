#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
	int fact[ 11 ] = { 1 }, ans[ 100001 ] = { 0 };

	for( int i = 1; i < 11; ++i )
		fact[ i ] = i * fact[ i-1 ];
	fill( ans + 1, ans + 100001, INT_MAX );
	for( int i = 1; i < 100001; ++i )
		for( int j = 0; fact[ j ] <= i; ++j )
			ans[ i ] = min( ans[ i ], 1 + ans[ i - fact[ j ] ] );
	for( int n; scanf( "%d", &n ) == 1; printf( "%d\n", ans[ n ] ) );
}
