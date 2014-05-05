#include<cstdio>
#include<cmath>
double ans[ 10000001 ] = { 0, 1 };
int in, t;

int main()
{
    scanf( "%d", &t );

    for( int i = 2; i <= 10000000; ++i )
        ans[ i ] = ans[ i-1 ] + log10( i );
    while( t-- )
        scanf( "%d", &in ), printf( "%d\n", int( ans[ in ] ) );

    return 0;
}