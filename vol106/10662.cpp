#include<bits/stdc++.h>
using namespace std;

int main()
{
	int T, R, H, pt[ 20 ], pr[ 20 ], ph[ 20 ], tr[ 20 ][ 20 ], rh[ 20 ][ 20 ], ht[ 20 ][ 20 ];

	while( scanf( "%d %d %d", &T, &R, &H ) == 3 )
	{
		for( int i = 0; i < T; ++i )
		{
			scanf( "%d", pt + i );
			for( int j = 0; j < R; ++j )
				scanf( "%d", tr[ i ] + j );
		}
		for( int i = 0; i < R; ++i )
		{
			scanf( "%d", pr + i );
			for( int j = 0; j < H; ++j )
				scanf( "%d", rh[ i ] + j );
		}
		for( int i = 0; i < H; ++i )
		{
			scanf( "%d", ph + i );
			for( int j = 0; j < T; ++j )
				scanf( "%d", ht[ i ] + j );
		}

		int cost = INT_MAX, t, r, h;

		for( int i = 0; i < T; ++i )
			for( int j = 0; j < R; ++j )
				for( int k = 0; k < H; ++k )
					if( !tr[ i ][ j ] && !rh[ j ][ k ] && !ht[ k ][ i ] && cost > pt[ i ] + pr[ j ] + ph[ k ] )
					{
						cost = pt[ i ] + pr[ j ] + ph[ k ];
						t = i;
						r = j;
						h = k;
					}
		if( cost == INT_MAX )
			puts( "Don't get married!" );
		else
			printf( "%d %d %d:%d\n", t, r, h, cost );
	}
}
