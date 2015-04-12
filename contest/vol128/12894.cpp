#include<cstdio>

int main()
{
	scanf( "%*s" );
	for( int x0, y0, x1, y1, cx, cy, r; scanf( "%d %d %d %d %d %d %d", &x0, &y0, &x1, &y1, &cx, &cy, &r ) == 7; )
	{
		int H = y1 - y0, W = x1 - x0;
		if( H*5 != W*3 || r*5 != W || H % 2 || cy != y0 + H/2 || W % 20 || cx != x0 + 9*W/20 )
			puts( "NO" );
		else
			puts( "YES" );
	}
}
