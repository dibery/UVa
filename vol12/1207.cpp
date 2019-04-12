#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	char a[ 10000 ], b[ 10000 ];
	int la, lb;

	while( scanf( "%d %s %d %s", &la, a+1, &lb, b+1 ) == 4 )
	{
		int cell[ la + 1 ][ lb + 1 ];

		for( int i = 0; i <= la; ++i )
			cell[ i ][ 0 ] = i;
		for( int i = 1; i <= lb; ++i )
			cell[ 0 ][ i ] = i;
		for( int i = 1; i <= la; ++i )
			for( int j = 1; j <= lb; ++j )
				if( a[ i ] == b[ j ] )
					cell[ i ][ j ] = cell[ i-1 ][ j-1 ];
				else
					cell[ i ][ j ] = min( cell[ i-1 ][ j-1 ], min( cell[ i-1 ][ j ], cell[ i ][ j-1 ] ) ) + 1;

		printf( "%d\n", cell[ la ][ lb ] );
	}
}
