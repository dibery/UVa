#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 1 << 16;

int main()
{
	int bit1[ N ] = { 0 }, man, capw, capk;

	for( int i = 1; i < N; ++i )
		bit1[ i ] = 1 + bit1[ i ^ ( i & -i ) ];

	while( scanf( "%d %d %d", &man, &capw, &capk ) == 3 )
	{
		int w[ 16 ] = { 0 }, allw[ N ] = { 0 }, ans[ N ][ 2 ] = { { 0 } };
		vector<int> oneboat;

		for( int i = 0; i < man; ++i )
			scanf( "%d", w + i );
		for( int i = 0; i < man; ++i )
			allw[ 1 << i ] = w[ i ];
		for( int i = 1; i < 1 << man; ++i )
		{
			allw[ i ] = allw[ i & -i ] + allw[ i ^ ( i & -i ) ];
			if( bit1[ i ] <= capk && allw[ i ] <= capw )
				oneboat.push_back( i );
		}

		fill( ans[ 0 ], ans[ 1 << man ], INT_MAX );
		ans[ ( 1 << man ) - 1 ][ 0 ] = 0;
		queue<pii> bfs;

		for( bfs.push( pii( ( 1 << man ) - 1, 0 ) ); !bfs.empty(); bfs.pop() )
		{
			pii F = bfs.front();
			int f = F.first;
			if( F.second )
			{
				int next = f | ( ( f + 1 ) & ( -f - 1 ) );
				if( ans[ next ][ 0 ] == INT_MAX )
					ans[ next ][ 0 ] = ans[ f ][ 1 ] + 1, bfs.push( pii( next, 0 ) );
			}
			else
				for( int i: oneboat )
					if( ( f & i ) == i && ans[ f ^ i ][ 1 ] == INT_MAX )
						ans[ f ^ i ][ 1 ] = ans[ f ][ 0 ] + 1, bfs.push( pii( f ^ i, 1 ) );
		}
		printf( "%d\n", ans[ 0 ][ 1 ] == INT_MAX? -1 : ans[ 0 ][ 1 ] );
	}
}
