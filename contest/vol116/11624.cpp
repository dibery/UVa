#include<bits/stdc++.h>
using namespace std;

char brd[ 1005 ][ 1005 ];
int jtime[ 1005 ][ 1005 ], ftime[ 1005 ][ 1005 ];

void bfs( queue<pair<int,int>>& q, int time[ 1005 ][ 1005 ] )
{
	for( ; !q.empty(); q.pop() )
	{
		auto& f = q.front();
		for( int i = f.first - 1; i <= f.first + 1; ++i )
			for( int j = f.second - 1; j <= f.second + 1; ++j )
				if( i == f.first ^ j == f.second && time[ i ][ j ] == INT_MAX && brd[ i ][ j ] != '#' )
				{
					time[ i ][ j ] = time[ f.first ][ f.second ] + 1;
					if( brd[ i ][ j ] )
						q.emplace( i, j );
				}
	}
}

int main()
{
	int t, r, c;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &r, &c ); )
	{
		fill( jtime[ 0 ], jtime[ 1005 ], INT_MAX );
		fill( ftime[ 0 ], ftime[ 1005 ], INT_MAX );
		memset( brd, 0, sizeof( brd ) );
		queue<pair<int,int>> J, F;
		int esc = INT_MAX;

		for( int i = 1; i <= r; ++i )
		{
			scanf( "%s", brd[ i ] + 1 );
			for( int j = 1; j <= c; ++j )
				if( brd[ i ][ j ] == 'J' )
					J.emplace( i, j ), jtime[ i ][ j ] = 0;
				else if( brd[ i ][ j ] == 'F' )
					F.emplace( i, j ), ftime[ i ][ j ] = 0;
		}

		bfs( J, jtime );
		bfs( F, ftime );
		for( int i = 1; i <= c; ++i )
		{
			if( jtime[ 0 ][ i ] < ftime[ 0 ][ i ] )
				esc = min( esc, jtime[ 0 ][ i ] );
			if( jtime[ r + 1 ][ i ] < ftime[ r + 1 ][ i ] )
				esc = min( esc, jtime[ r + 1 ][ i ] );
		}
		for( int i = 1; i <= r; ++i )
		{
			if( jtime[ i ][ 0 ] < ftime[ i ][ 0 ] )
				esc = min( esc, jtime[ i ][ 0 ] );
			if( jtime[ i ][ c + 1 ] < ftime[ i ][ c + 1 ] )
				esc = min( esc, jtime[ i ][ c + 1 ] );
		}

		if( esc == INT_MAX )
			puts( "IMPOSSIBLE" );
		else
			printf( "%d\n", esc );
	}
}
