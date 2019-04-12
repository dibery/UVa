#include<cstdio>
#include<cmath>

inline double exp( double n ) { return n * n / 6; }

int main()
{
	for( int xl, yl, xr, yr; scanf( "%d %d %d %d", &xl, &yl, &xr, &yr ) == 4; )
		printf( "%.8f\n", exp( xr - xl ) + exp( yr - yl ) );
}
