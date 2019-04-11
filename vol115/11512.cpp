#include<cstdio>
#include<cstring>

class node
{
	public:
		node() { times = 1; memset( next, 0, sizeof( next ) ); }
		~node() {
			for( int i = 0; i < 4; ++i )
				if( next[ i ] )
					delete next[ i ];
		}
		int times;
		node* next[ 4 ];
};

int main()
{
	int t;

	for( scanf( "%d\n", &t ); t--; )
	{
		char s[ 1001 ], ans[ 1001 ] = { 0 }, map[] = { "ACGT" };
		int len = strlen( gets( s ) ), alen = 0, atime = 0;
		node root;

		for( int i = 0; i < len; ++i )
			s[ i ] = strchr( map, s[ i ] ) - map;
		for( int i = 0; i < len; ++i )
		{
			node* pos = &root;
			for( int j = i; j < len; ++j )
				if( pos->next[ s[ j ] ] )
				{
					pos = pos->next[ s[ j ] ];
					pos->times++;
					if( j-i+1 > alen || j-i+1 == alen && memcmp( s+i, ans, alen ) <= 0 )
					{
						memcpy( ans, s+i, j-i+1 );
						alen = j-i+1;
						atime = pos->times;
					}
				}
				else
					pos = pos->next[ s[ j ] ] = new node;
		}
		for( int i = 0; i < alen; ++i )
			ans[ i ] = map[ ans[ i ] ];
		if( atime )
			printf( "%s %d\n", ans, atime );
		else
			puts( "No repetitions found!" );
	}
}
