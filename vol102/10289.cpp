#include<cstdio>
#include<cmath>

int main()
{
	double s2 = sqrt( 2 ), s3 = sqrt( 3 ), s6 = sqrt( 6 );
	double coef[] = { 1 / cos( M_PI / 12 ), s2 / s3, 2 * s2 / ( s3 + s6 ), s3 / ( 1 + s3 ), ( 11 + 7 * s3 - sqrt( 6 * s3 + 4 ) ) / ( 21 + 8 * s3 ), ( s3 + 1 ) / 3 / s3, ( s3 + 1 ) / ( s3 + 4 ) };

	for( double n; scanf( "%lf", &n ) == 1; )
		for( int i = 0; i < 7; ++i )
			printf( "%.10f%c", coef[ i ] * n, i == 6? '\n' : ' ' );
}
