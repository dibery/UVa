#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct out
{
	int a, b, c;
}tmp;
bool cmp( out a, out b )
{
	if( a.a != b.a )
		return a.a < b.a;
	if( a.b != b.b )
		return a.b < b.b;
	return a.c < b.c;
}

int main()
{
	int size;

	while( scanf( "%d", &size ) != EOF )
	{
		int eat[ size ][ size ], ans = 0;
		vector<out> all;

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%d", eat[ i ] + j );
		for( int i = 0; i < size; ++i )
			for( int j = i+1; j < size; ++j )
				for( int k = j+1; k < size; ++k )
					if( eat[ i ][ j ] && eat[ j ][ k ] && eat[ k ][ i ] )
					{
						++ans;
						tmp.a = i + 1;
						tmp.b = j + 1;
						tmp.c = k + 1;
						all.push_back( tmp );
					}
		for( int i = size-1; i; --i )
			for( int j = i-1; j; --j )
				for( int k = j-1; k >= 0; --k )
					if( eat[ i ][ j ] && eat[ j ][ k ] && eat[ k ][ i ] )
					{
						++ans;
						tmp.a = i + 1;
						tmp.b = j + 1;
						tmp.c = k + 1;
						all.push_back( tmp );
					}
		sort( all.begin(), all.end(), cmp );
		for( int i = 0; i < all.size(); ++i )
			printf( "%d %d %d\n", all[ i ].a, all[ i ].b, all[ i ].c );
		printf( "total:%d\n\n", ans );
	}

	return 0;
}
