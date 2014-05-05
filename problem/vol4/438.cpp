#include<cstdio>
#include<cmath>
inline double dist( double x, double y ) { return sqrt( x*x + y*y ); }

int main()
{
    double x1, y1, x2, y2, x3, y3, cosine, sine, pi = acos( -1 );

    while( scanf( "%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3 ) != EOF )
    {
        cosine = ( ( x2-x1 ) * ( x3-x1 ) + ( y2-y1 ) * ( y3-y1 ) ) / dist( y2-y1, x2-x1 ) / dist( y3-y1, x3-x1 );
        sine = sqrt( 1 - cosine*cosine );
        printf( "%.2lf\n", dist( y2-y3, x2-x3 ) / sine * pi + 1e-12 );
    }

	return 0;
}