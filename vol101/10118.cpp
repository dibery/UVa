#include<cstdio>
#include<cstring>
#include<algorithm>

int pile[ 4 ][ 41 ], ans;
bool vis[ 41 ][ 41 ][ 41 ][ 41 ];

void find( int a, int b, int c, int d, int container = 0, int size = 0, int won = 0 )
{
	if( a >= 0 && b >= 0 && c >= 0 && d >= 0 && size < 5 )
		if( vis[ a ][ b ][ c ][ d ] )
			return;
		else
			vis[ a ][ b ][ c ][ d ] = true, ans = std::max( ans, won );
	else
		return;

	int h[] = { a, b, c, d };

	for( int i = 0; i < 4; ++i )
		if( h[ i ] )
		{
			if( container & 1 << pile[ i ][ h[ i ] ] )
				find( a - ( i == 0 ), b - ( i == 1 ), c - ( i == 2 ), d - ( i == 3 ), container ^ 1 << pile[ i ][ h[ i ] ], size-1, won+1 );
			else
				find( a - ( i == 0 ), b - ( i == 1 ), c - ( i == 2 ), d - ( i == 3 ), container ^ 1 << pile[ i ][ h[ i ] ], size+1, won );
		}
}

int main()
{
	int h;

	while( scanf( "%d", &h ) && h )
	{
		memset( vis, false, sizeof( vis ) );
		ans = 0;

		for( int i = h; i; --i )
			for( int j = 0; j < 4; ++j )
				scanf( "%d", pile[ j ] + i ), --pile[ j ][ i ];

		find( h, h, h, h );
		printf( "%d\n", ans );
	}
}
