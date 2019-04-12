#include<cstdio>
#include<list>
using namespace std;

class node
{
	public:
		int pos, val;
		node( int p = 0, int v = 0 ) { pos = p; val = v; }
};

int main()
{
	int h, w, size, pos[ 10000 ], val;

	while( scanf( "%d %d", &h, &w ) == 2 )
	{
		list<node> lst[ 10000 ];
		
		for( int i = 0; i < h; ++i )
		{
			scanf( "%d", &size );
			for( int j = 0; j < size; ++j )
				scanf( "%d", pos+j );
			for( int j = 0; j < size; ++j )
				scanf( "%d", &val ), lst[ pos[ j ]-1 ].push_back( node( i+1, val ) );
		}

		printf( "%d %d\n", w, h );
		for( int i = 0; i < w; ++i )
		{
			printf( "%u", lst[ i ].size() );
			for( list<node>::iterator it = lst[ i ].begin(); it != lst[ i ].end(); ++it )
				printf( " %d", it->pos );
			puts( "" );
			for( list<node>::iterator it = lst[ i ].begin(); it != lst[ i ].end(); ++it )
				printf( "%s%d", it == lst[ i ].begin()? "" : " ", it->val );
			puts( "" );
		}
	}
}
