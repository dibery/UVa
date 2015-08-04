#include<cstdio>
#include<cmath>

int main()
{
	int t, n, sum, lim;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &n );
		if( n < 0 )
			n = -n;
		lim = ceil( ( sqrt( 8.0*n + 1 ) - 1 ) / 2 );
		sum = ( 1 + lim ) * lim / 2;
		if( lim == 0 )
			lim = 3;
		if( ( sum - n ) % 2 == 0 )
			printf( "%d\n", lim );
		else//
			printf( "%d\n", lim % 2 == 0? lim+1 : lim+2 );
		if( t )
			puts( "" );
	}
}
