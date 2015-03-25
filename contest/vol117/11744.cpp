#include<cstdio>
#include<climits>
#include<cstdlib>

void bin( unsigned int a, char c )
{
	if( a >= INT_MAX )
		printf( "overflow" );
	else
		for( int i = 30; i >= 0; --i )
			printf( "%d", ( 1 << i & a ) != 0 );
	putchar( c );
}

int main()
{
	unsigned int n, va, vb, vc, vd;
	char a[ 32 ], b[ 32 ];

	for( scanf( "%u", &n ); n--; )
	{
		scanf( "%s %s", a, b );
		bin( va = strtol( a, NULL, 2 ), ' ' );
		bin( vb = strtol( b, NULL, 2 ), '\n' );
		while( !( vb == 0 || vb >= INT_MAX ) )
		{
			vc = va ^ vb;
			vd = va & vb;
			bin( va = vc, ' ' );
			bin( vb = vd << 1, '\n' );
		}
		if( n )
			puts( "" );
	}
}
