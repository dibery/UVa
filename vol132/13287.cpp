#include<cstdio>

int main()
{
	for( int w, piece; scanf( "%d %d", &w, &piece ) == 2; )
	{
		int area = 0;
		for( int x, y; piece-- && scanf( "%d %d", &x, &y ); )
			area += x * y;
		printf( "%d\n", area / w );
	}
}
