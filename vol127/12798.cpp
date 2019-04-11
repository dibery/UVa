#include<cstdio>

int main()
{
	for( int player, match; scanf( "%d %d", &player, &match ) == 2; )
	{
		int ans = 0;

		for( int i = 0; i < player; ++i )
		{
			bool ok = true;
			for( int n, j = 0; j < match; ++j )
				scanf( "%d", &n ), ok &= n != 0;
			ans += ok;
		}
		printf( "%d\n", ans );
	}
}
