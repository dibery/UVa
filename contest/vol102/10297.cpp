#include<cstdio>
#include<cmath>

int main()
{
    double d, v, pi = 3.141592653589;

    while( scanf( "%lf %lf", &d, &v ) && ( d || v ) )
        printf( "%.3f\n", pow( d*d*d - 6*v/pi, 1.0/3.0 ) );

    return 0;
}