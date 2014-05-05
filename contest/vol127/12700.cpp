#include<cstdio>

int main()
{
	int t, len;
	char in[ 101 ] = { 0 };
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		int b = 0, w = 0, t = 0;
		scanf( "%d\n%s", &len, in );
		for( int i = 0; in[ i ]; ++i )
			if( in[ i ] == 'B' )
				++b;
			else if( in[ i ] == 'W' )
				++w;
			else if( in[ i ] == 'T' )
				++t;
		if( !b && !w && !t )
			printf( "Case %d: ABANDONED\n", n );
		else if( b == w )
			printf( "Case %d: DRAW %d %d\n", n, b, t );
		else if( !b && !t )
			printf( "Case %d: WHITEWASH\n", n );
		else if( !w && !t )
			printf( "Case %d: BANGLAWASH\n", n );
		else if( w > b )
			printf( "Case %d: WWW %d - %d\n", n, w, b );
		else if( b > w )
			printf( "Case %d: BANGLADESH %d - %d\n", n, b, w );
	}

	return 0;
}
