#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( double v, time, x[ 2000 ], y[ 2000 ]; scanf( "%lf %lf\n", &v, &time ) && v; )
	{
		int size = 0, dist[ 2000 ] = { 0 };
		queue<int> bfs;

		v *= 60;
		for( char s[ 500 ]; gets( s ) && *s; ++size )
			sscanf( s, "%lf %lf", x + size, y + size );

		fill( dist + 1, dist + size, INT_MAX );
		for( bfs.push( 0 ); !bfs.empty() && bfs.front() != 1; bfs.pop() )
			for( int i = 0, f = bfs.front(); i < size; ++i )
				if( dist[ i ] == INT_MAX && hypot( x[ i ] - x[ f ], y[ i ] - y[ f ] ) + 1e-9 <= v * time )
					dist[ i ] = dist[ f ] + 1, bfs.push( i );
		if( dist[ 1 ] == INT_MAX )
			puts( "No." );
		else
			printf( "Yes, visiting %d other holes.\n", dist[ 1 ] - 1 );
	}
}
