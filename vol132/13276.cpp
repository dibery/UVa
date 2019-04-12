#include<cstdio>
#include<cmath>

double ans( double e, double p, double k, double r )
{
	if( p * k >= e )
		return ceil( e / p );
	else if( p * k <= r )
		return -1;
	double round = ceil( ( e - p * k ) / ( p * k - r ) );
	return round * k + ceil( ( e - ( p * k - r ) * round ) / p );
}

int main()
{
	int n, e, p, k, r;

	scanf( "%d", &n );
	for( int i = 1; i <= n && scanf( "%d %d %d %d", &e, &p, &k, &r ); ++i )
		printf( "Case %d: %.0f\n", i, ans( e, p, k, r ) );
}
