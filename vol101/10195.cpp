#include<cstdio>
#include<cmath>

int main()
{
    double a, b, c, s, pi = acos( -1 );

    while( scanf( "%lf %lf %lf", &a, &b, &c ) == 3 )
    {
        s = ( a + b + c ) / 2;
        printf( "The radius of the round table is: %.3f\n", a*b*c? 2 * sqrt( s * ( s-a ) * ( s-b ) * ( s-c ) ) / ( a + b + c ) : 0 );
    }
}
