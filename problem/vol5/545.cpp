#include<cstdio>
#include<cmath>
int main()
{
    int n, exp, t;
    scanf( "%d", &t );
    while( t-- )
    {
        scanf( "%d", &n );
        exp = floor( log10( 2 ) * -n );
        printf( "2^-%d = %.3lfE%d\n", n, pow( 10, log10( 2 ) * -n - exp ), exp );
    }
    return 0;
}
