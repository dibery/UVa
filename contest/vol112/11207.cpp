#include<cstdio>
#include<algorithm>
using namespace std;
float calc( int l, int w )
{
	if( l > w )
		swap( l, w );
	if( w / l >= 4 )
		return l;
	return max( l / 2.0, w / 4.0 );
}

int main()
{
	int size, l, w;

	while( scanf( "%d", &size ) && size )
	{
		int ans = 0;
		float len = 0;

		for( int i = 1; i <= size; ++i )
		{
			scanf( "%d %d", &l, &w );
			if( calc( l, w ) > len )
				len = calc( l, w ), ans = i;
		}
		printf( "%d\n", ans );
	}
}
