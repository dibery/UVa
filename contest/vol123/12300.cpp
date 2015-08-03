#include<cstdio>
#include<cmath>

int main()
{
	for( int xa, ya, xb, yb, n; scanf( "%d %d %d %d %d", &xa, &ya, &xb, &yb, &n ) && n; )
	{
			double l = ( ( xa - xb ) * ( xa - xb ) + ( ya - yb ) * ( ya - yb ) ) / ( 1 - cos( n / 2 * 2 * M_PI / n ) ) / 2;
			printf( "%f\n", l * sin( 2 * M_PI / n ) / 2 * n );
	}
}
