#include<cstdio>

int main()
{
	int t, h, m, ans;
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d:%d", &h, &m );
		ans = 720 - 60 * h - m;
		if( ans < 60 )
			ans += 720;
		printf( "%02d:%02d\n", ans / 60, ans % 60 );
	}

	return 0;
}
