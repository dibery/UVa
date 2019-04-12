#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	for( int x1, y1, x2, y2; scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 ) && x1; )
	{
		if( x1 > x2 )
			swap( x1, x2 ), swap( y1, y2 );
		if( y1 > y2 )
			y2 = y1 * 2 - y2;
		int dx = x2 - x1, dy = y2 - y1;

		if( dy >= dx )
			printf( "%d\n", dx + dy );
		else if( x1 + y1 & 1 )
			printf( "%d\n", dx * 2 + ( ( x2 + y2 ) % 2 == 0 ) );
		else
			printf( "%d\n", dx * 2 - 1 + ( ( x2 + y2 ) % 2 == 0 ) );
	}
}
