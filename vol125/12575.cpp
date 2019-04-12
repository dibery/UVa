#include<cstdio>
#include<cmath>

int main()
{
    int t;
    double a, b, pi = acos( -1 ), eps = 1e-14;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%lf %lf", &a, &b );
        double len = sqrt( a*a + b*b ), theta = len? acos( a / len ) : pi / 2;
        if( b < 0 )
            theta = 2 * pi - theta;
        printf( "%.2lf %.2lf\n", ( theta > pi / 2? 2.5 * pi - theta : pi / 2 - theta )+eps, len+eps );
    }

	return 0;
}