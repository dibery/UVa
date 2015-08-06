#include<cstdio>

int main()
{
	int t, n, item, man;

	for( scanf( "%d", &t ); t--; )
	{
		int time[ 32 ] = { 0 }, ans = 1;

		scanf( "%d %d", &item, &man );
		for( int i = 0; i < man; ++i )
			for( int j = 0; j < item; ++j )
			{
				scanf( "%d", &n );
				if( n == 1 )
					++time[ j ];
			}
		for( int i = 0; i < 32; ++i )
			if( time[ i ] )
				ans *= time[ i ];
		printf( "%d\n", ans );
	}
}
