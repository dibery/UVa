#include<cstdio>
#include<cmath>

int main()
{
    int t;
    double a, c, pi = 3.141592653589793;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%lf %lf", &c, &a );
        printf( "%.3f\n", pi * a * sqrt( a*a - c*c ) / 4 );
    }

	return 0;
}