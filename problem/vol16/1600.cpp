#include<bits/stdc++.h>
#define nx ( H + dx[ d ] )
#define ny ( W + dy[ d ] )
#define nt ( brd[ nx ][ ny ]? T-1 : turbo )
using namespace std;
typedef pair<int,int> pii;
const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };

int main()
{
	int t, h, w, turbo, brd[ 20 ][ 20 ], dist[ 20 ][ 20 ][ 21 ];
	
	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d %d", &h, &w, &turbo );
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				scanf( "%d", brd[ i ] + j );

		queue<pii> bfs;
		bool vis[ 20 ][ 20 ][ 21 ] = { { { true } } };
		fill( dist[ 0 ][ 0 ], dist[ 20 ][ 0 ], INT_MAX );
		dist[ 0 ][ 0 ][ turbo ] = 0;
		bfs.push( make_pair( 0, turbo ) ); // pos-turbo

		while( !bfs.empty() )
		{
			int H = bfs.front().first / 100, W = bfs.front().first % 100, T = bfs.front().second;
			if( H == h-1 && W == w-1 )
				break;
			bfs.pop();
			vis[ H ][ W ][ T ] = true;
			for( int d = 0; d < 4; ++d )
				if( nx < h && ny < w && nx >= 0 && ny >= 0 && T - brd[ nx ][ ny ] >= 0 && dist[ nx ][ ny ][ nt ] == INT_MAX )
				{
					dist[ nx ][ ny ][ nt ] = dist[ H ][ W ][ T ] + 1;
					bfs.push( make_pair( nx*100 + ny, nt ) );
				}
		}

		int D = INT_MAX;
		for( int i = 0; i <= turbo; ++i )
			D = min( D, dist[ h-1 ][ w-1 ][ i ] );
		printf( "%d\n", D == INT_MAX? -1 : D );
	}
}
