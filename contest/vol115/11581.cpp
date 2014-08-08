#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
	int t;
	char str[ 10 ], *mat[ 3 ] = { str, str+3, str+6 };
	
	for( scanf( "%d", &t ); t--; )
	{
		bool vis[ 512 ] = { false };
		int history[ 512 ] = { 0 }, size = 0, ans;
		for( int i = 0; i < 3; ++i )
			scanf( "%s", mat[ i ] );
		do
		{
			char tmp[ 10 ] = { 0 };
			vis[ strtol( str, NULL, 2 ) ] = true;
			history[ size++ ] = strtol( str, NULL, 2 );
			for( int i = 0; i < 9; ++i )
				for( int m = i/3 - 1; m <= i/3 + 1; ++m )
					for( int n = i%3 - 1; n <= i%3 + 1; ++n )
						if( m >= 0 && n >= 0 && m < 3 && n < 3 && m == i/3 ^ n == i%3 && mat[ m ][ n ] == '1' )
							++tmp[ i ];
			for( int i = 0; i < 9; ++i )
				tmp[ i ] = tmp[ i ] % 2 + '0';
			strcpy( str, tmp );
		} while( !vis[ strtol( str, NULL, 2 ) ] );

		int hit = strtol( str, NULL, 2 );
		for( ans = 0; history[ ans ] != hit; ++ans );
		printf( "%d\n", ans - 1 );
	}
}
