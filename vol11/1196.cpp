#include<cstdio>
#include<algorithm>
using namespace std;

class node
{
	public:
		node( int H = 0, int M = 0 ) { h = H; m = M; }
		bool operator< ( const node& rhs ) { return rhs.h == h? m < rhs.m : h < rhs.h; }
		int h, m;
};

int main()
{
	int size, h, m;

	while( scanf( "%d", &size ) && size )
	{
		int lis[ 10000 ] = { 0 }, ans = 0;
		node* list = new node[ size ];
		fill( lis, lis+size, 1 );

		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &h, &m ), list[ i ] = node( h, m );
		sort( list, list+size );
		for( int i = size-2; i >= 0; ans = std::max( ans, lis[ i-- ] ) )
			for( int j = size-1; j > i; --j )
				if( list[ i ].m <= list[ j ].m )
					lis[ i ] = std::max( lis[ i ], lis[ j ]+1 );

		printf( "%d\n", ans );
		delete[] list;
	}
	puts( "*" );
}
