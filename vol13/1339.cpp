#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	for( char a[ 101 ], b[ 101 ]; gets( a ) && gets( b ); )
	{
		int fa[ 26 ] = { 0 }, fb[ 26 ] = { 0 };
		for( int i = 0; a[ i ]; ++i )
			++fa[ a[ i ] - 'A' ], ++fb[ b[ i ] - 'A' ];
		sort( fa, fa+26 );
		sort( fb, fb+26 );
		puts( equal( fa, fa+26, fb )? "YES" : "NO" );
	}
}
