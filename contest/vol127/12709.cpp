#include<cstdio>

int main()
{
	for( int N, vol = 0, H = 0; scanf( "%d", &N ) && N; H = vol = 0 )
	{
		for( int i = 0, l, w, h; i < N; ++i )
		{
			scanf( "%d %d %d", &l, &w, &h );
			if( h > H || h == H && l * w * h > vol )
				vol = l * w * h, H = h;
		}
		printf( "%d\n", vol );
	}
}
