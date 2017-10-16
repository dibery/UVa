#include<bits/stdc++.h>
using namespace std;

struct triangle
{
	long double a, b, c;
	triangle( long double x, long double y, long double z )
	{
		long double l[] = { x, y, z };
		sort( l, l + 3 );
		a = l[ 0 ], b = l[ 1 ], c = l[ 2 ];
	}
	bool operator< ( triangle t ) const
	{
		return abs( b / a - t.b / t.a ) < DBL_EPSILON? 
			c / a < t.c / t.a - DBL_EPSILON : b / a < t.b / t.a - DBL_EPSILON;
	}
};

int main()
{
	int t;
	double a, b, c;

	scanf( "%d", &t );
	for( int z = 1; z <= t && scanf( "%lf %lf %lf", &a, &b, &c ); ++z )
	{
		set<triangle> shape;
		queue<triangle> bfs;

		for( bfs.emplace( a, b, c ), shape.emplace( a, b, c ); !bfs.empty(); bfs.pop() )
		{
			triangle f = bfs.front();
			long double mid = sqrt( pow( f.a, 2 ) / 2 + pow( f.b, 2 ) / 2 - pow( f.c, 2 ) / 4 );
			triangle p( mid, f.c / 2, f.a ), q( mid, f.c / 2, f.b );
			if( shape.find( p ) == shape.end() )
				shape.insert( p ), bfs.push( p );
			if( shape.find( q ) == shape.end() )
				shape.insert( q ), bfs.push( q );
		}

		printf( "Triangle %d: %llu\n", z, shape.size() );
	}
}
