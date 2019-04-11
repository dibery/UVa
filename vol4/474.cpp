#include<cstdio>
#include<cmath>
int main()
{
    int n, exp;
    while( scanf( "%d", &n ) != EOF )
    {
        exp = floor( log10( 2 ) * ( -n ) );
        printf( "2^-%d = %.3fe%d\n", n, pow( 10, log10( 2 ) * ( -n ) - exp - 1e-12 ), exp );
    }
    return 0;
}
