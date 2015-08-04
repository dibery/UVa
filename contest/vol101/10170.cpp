#include<cstdio>
#include<cmath>
inline double calc( long long int x2, long long int x, long long int c )
{
    return ( sqrt( x*x - 4*x2*c ) - x ) / 2*x2;
}

int main()
{
    long long int b, e;

    while( scanf( "%lld %lld", &b, &e ) == 2 )
        printf( "%.0lf\n", ceil( calc( 1, 1, -b*b + b - 2*e ) ) );
}
