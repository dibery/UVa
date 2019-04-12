#include<cstdio>
#include<cstring>

int main()
{
	int t;
	char brd[ 26 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		for( int i = 0; i < 5; ++i )
			scanf( "%s", brd + 5 * i );

		char *p = strchr( brd, '<' );
		bool rev = p;
		if( !p )
			p = strchr( brd, '>' );
		int col = strchr( brd, '|' ) - brd;

		printf( "Case %d: %s Ball\n", n, rev ^ ( ( p - brd ) % 5 < col )? "Thik" : "No" );
	}
}
