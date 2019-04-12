#include<cstdio>
#include<cmath>

inline double calc( double r1, double r2 )
{
	double r = r1 + r2;
	return ( r*r - r1*r1 - r2*r2 ) * M_PI;
}

int main()
{
	int t, a, b;
	char s[ 30 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		gets( s );
		if( sscanf( s, "%d %d", &a, &b ) == 2 )
			printf( "%.4f\n", calc( a, b ) );
		else
			printf( "%.4f\n", calc( a / 4., a / 4. ) );
	}
}
