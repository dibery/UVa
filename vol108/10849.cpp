#include<cstdio>

int main()
{
	int t, n, xbegin, ybegin, xend, yend;

	for( scanf( "%d", &t ); t; --t )
		for( scanf( "%d %*d", &n ); n; --n )
		{
			scanf( "%d %d %d %d", &xbegin, &ybegin, &xend, &yend );
			if( xbegin == xend && ybegin == yend )
				puts( "0" );
			else if( xbegin + ybegin == xend + yend || xbegin - ybegin == xend - yend )
				puts( "1" );
			else if( ( xbegin + ybegin ) % 2 == ( xend + yend ) % 2 )
				puts( "2" );
			else
				puts( "no move" );
		}
}
