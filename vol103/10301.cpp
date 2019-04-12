#include<cstdio>
#include<cmath>
#include<algorithm>

struct node
{
	double x, y, r;
	bool intersect( node& n )
	{
		double D = hypot( n.x - x, n.y - y ), R1 = r + n.r, R2 = fabs( r - n.r );
		return D <= R1 && D >= R2;
	}
} point[ 99 ];

int dfs( int pos, int size, bool adj[ 99 ][ 99 ], bool vis[ 99 ] )
{
	int ans = 0;
	vis[ pos ] = true;
	for( int i = 0; i < size; ++i )
		if( !vis[ i ] && adj[ pos ][ i ] )
			ans += dfs( i, size, adj, vis );
	return 1 + ans;
}

int main()
{
	for( int size; scanf( "%d", &size ) && size != -1; )
	{
		bool adj[ 99 ][ 99 ] = { { false } }, vis[ 99 ] = { false };
		int ans = 0;

		for( int i = 0; i < size; ++i )
			scanf( "%lf %lf %lf", &point[ i ].x, &point[ i ].y, &point[ i ].r );
		for( int i = 0; i < size; ++i )
			for( int j = i+1; j < size; ++j )
				if( point[ i ].intersect( point[ j ] ) )
					adj[ i ][ j ] = adj[ j ][ i ] = true;
		for( int i = 0; i < size; ++i )
			if( !vis[ i ] )
				ans = std::max( ans, dfs( i, size, adj, vis ) );
		printf( "The largest component contains %d ring%s.\n", ans, ans != 1? "s" : "" );
	}
}
