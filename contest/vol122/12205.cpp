#include<cstdio>

int main()
{
	int call, interval, s, e;

	while( scanf( "%d %d", &call, &interval ) == 2 && call + interval )
	{
		int start[ call ], end[ call ];
		for( int i = 0; i < call; ++i )
		{
			scanf( "%*d %*d %d %d", &s, &e );
			e += s;
			start[ i ] = s;
			end[ i ] = e;
		}
		for( int i = 0; i < interval; ++i )
		{
			int ans = 0;
			scanf( "%d %d", &s, &e );
			e += s;
			for( int i = 0; i < call; ++i )
				if( s < end[ i ] && e > start[ i ] )
					++ans;
			printf( "%d\n", ans );
		}
	}
	return 0;
}
