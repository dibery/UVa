#include<cstdio>
#include<cstdlib>
#include<climits>
using namespace std;

int max( int a, int b ) { return a > b? a : b; }
int solve( int* x, int* y, int begin, int end, int size )
{
	int mx = x[ begin ] - x[ end ], my = y[ begin ] - y[ end ], all = 2;
	for( int i = end+1; i < size; ++i )
	{
		int dx = x[ begin ] - x[ i ], dy = y[ begin ] - y[ i ];
		if( dx * my == dy * mx )
			++all;
	}
	return all;
}

int main()
{
	int n, x[ 700 ], y[ 700 ];
	char str[ 30 ];
	scanf( "%d\n", &n );

	while( n-- )
	{
		int ans = 0, size = 0;

		while( gets( str ) && *str )
			sscanf( str, "%d %d", x+size, y+size ), size++;
		for( int i = 0; i < size; ++i )
			for( int j = i+1; j < size; ++j )
				ans = max( ans, solve( x, y, i, j, size ) );
		printf( "%d%s\n", ans, n? "\n" : "" );
	}
}
