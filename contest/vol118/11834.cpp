#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

inline int sqr( int n ) { return n*n; }
inline bool check( int h, int w, int r1, int r2 )
{
	if( r1 * 2 > h || r1 * 2 > w || r2 * 2 > h || r2 * 2 > w )
		return false;
	return( sqr( h-r1-r2 ) + sqr( w-r1-r2 ) >= sqr( r1+r2 ) );
}

int main()
{
	int h, w, c2, c1;

	while( scanf( "%d %d %d %d", &h, &w, &c1, &c2 ) && h )
		puts( check( h, w, c1, c2 )? "S" : "N" );
}
