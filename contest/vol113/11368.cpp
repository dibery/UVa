#include<cstdio>
#include<algorithm>
using namespace std;
class doll
{
public:
	int h, w;
	doll( int W = -1, int H = -1 ) { w = W; h = H; }
	bool operator() ( const doll& a, const doll& b ) { return a.w == b.w? a.h > b.h : a.w < b.w; }
	bool operator< ( const doll& cmp ) { return h < cmp.h && w < cmp.w; }
} obj;

int main()
{
	int t, size;
	for( scanf( "%d", &t ); t--; )
	{
		int ans = 0;
		scanf( "%d", &size );
		doll *item = new doll[ size ], *nest = new doll[ size+1 ];
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &item[ i ].w, &item[ i ].h );
		sort( item, item+size, obj );

		for( int i = 0, j; i < size; ++i )
		{
			for( j = 0; ; ++j )
				if( nest[ j ].h < item[ i ].h && nest[ j ].w < item[ i ].w )
					break;
			nest[ j ] = item[ i ];
		}
		for( ans = 0; obj < nest[ ans ]; ++ans );
		printf( "%d\n", ans );
		delete item;
		delete nest;
	}
	return 0;
}
