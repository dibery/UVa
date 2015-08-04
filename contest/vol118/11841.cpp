#include<cstdio>
#include<cstdlib>

struct node
{
	node() { vis = false; scanf( "%d %d %d", &x, &y, &z ); }
	bool adj( const node& c ) { 
		int a = 0 + ( abs( x-c.x ) == 1 ) + ( abs( y-c.y ) == 1 ) + ( abs( z-c.z ) == 1 ),
				b = 0 + ( x == c.x ) + ( y == c.y ) + ( z == c.z );
		return a == 2 && b == 1;
	}
	bool side() { return !x || !y || !z; }
	int x, y, z;
	bool vis;
};

bool dfs( node* v, int index, bool& x, bool& y, bool& z, int size )
{
	if( x && y && z )
		return true;
	v[ index ].vis = true;
	for( int i = 0; i < size; ++i )
		if( !v[ i ].vis && v[ index ].adj( v[ i ] ) )
			if( dfs( v, i, x |= !v[ i ].x, y |= !v[ i ].y, z |= !v[ i ].z, size ) )
				return true;
	return false;
}

int main()
{
	for( int order, benny; scanf( "%d %d", &order, &benny ) && order+benny; )
	{
		node* has = new node[ benny ];
		bool ok = false, x, y, z;

		for( int i = 0; i < benny && !ok; ++i )
			if( !has[ i ].vis && has[ i ].side() )
				ok |= dfs( has, i, x = !has[ i ].x, y = !has[ i ].y, z = !has[ i ].z, benny );
		puts( ok? "Benny" : "Willy" );
	}
}
