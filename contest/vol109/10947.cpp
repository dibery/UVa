#include<cstdio>
#include<cmath>
#include<queue>
const int N = 102;

int main()
{
	for( int day, speed, x[ N ], y[ N ], r[ N ], trip, is; scanf( "%d %d", &day, &speed ) == 2; )
	{
		trip = day * speed;
		scanf( "%d %d %d %d %d %d %d", x, y, r, x + 1, y + 1, r + 1, &is );
		for( int i = 2; i < is + 2; ++i )
			scanf( "%d %d %d", x + i, y + i, r + i );

		bool vis[ N ] = { true };
		std::queue<int> bfs;
		
		for( bfs.push( 0 ); !bfs.empty(); bfs.pop() )
			for( int i = 0; i < is + 2; ++i )
				if( !vis[ i ] && hypot( x[ bfs.front() ] - x[ i ], y[ bfs.front() ] - y[ i ] ) - r[ bfs.front() ] - r[ i ] <= trip )
					bfs.push( i ), vis[ i ] = true;

		puts( vis[ 1 ]? "Larry and Ryan will escape!" : "Larry and Ryan will be eaten to death." );
	}
}
