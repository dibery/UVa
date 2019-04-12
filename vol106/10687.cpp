#include<cstdio>
#include<utility>
#include<algorithm>
#define x first
#define y second
using namespace std;
typedef pair<int,int> Point;

int sq( Point& A, Point& B )
{
	int dx = A.x - B.x, dy = A.y - B.y;

	return dx * dx + dy * dy;
}

void dfs( int adj[][ 2 ], bool vis[], int v )
{
	vis[ v ] = true;
	for( int i = 0; i < 2; ++i )
		if( !vis[ adj[ v ][ i ] ] )
			dfs( adj, vis, adj[ v ][ i ] );
}

int main()
{
	for( int size; scanf( "%d", &size ) && size; )
	{
		int adj[ 1000 ][ 2 ] = { { 0 } };
		Point point[ 1000 ];
		bool vis[ 1000 ] = { false };

		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &point[ i ].x, &point[ i ].y );
		if( size < 4 )
		{
			puts( "All stations are reachable." );
			continue;
		}

		for( int i = 0; i < size; ++i )
		{
			int D[ 1000 ] = { 0 };

#define A adj[ i ][ 0 ]
#define B adj[ i ][ 1 ]

			A = B = -1;

			for( int j = 0; j < size; ++j )
				if( i != j )
				{
					D[ j ] = sq( point[ i ], point[ j ] );
					if( A == -1 )
						A = j;
					else if( B == -1 )
						B = j;
					else if( D[ j ] < D[ A ] || ( D[ j ] == D[ A ] && point[ j ] < point[ A ] ) )
						B = A, A = j;
					else if( D[ j ] < D[ B ] || ( D[ j ] == D[ B ] && point[ j ] < point[ B ] ) )
						B = j;
				}
		}
		dfs( adj, vis, 0 );

		puts( find( vis, vis + size, false ) != vis + size? "There are stations that are unreachable." : "All stations are reachable." );
	}
}
