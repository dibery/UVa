#include<cstdio>
#include<cmath>

int main()
{
    int test;
    scanf( "%d", &test );

    while( test-- )
    {
        int coef[ 21 ] = { 0 }, index = 0, d, k;
        long long int ans = 0;
        scanf( "%d", &index );
        for( int i = 0; i <= index; ++i )
            scanf( "%d", coef+i );
        scanf( "%d %d", &d, &k );
        int item = ceil( ( -1+sqrt( 1.0 + 8.0*k/d ) ) / 2 );
        for( double i = 0; i <= 20; ++i )
            ans += coef[ int( i ) ] * pow( item, i );
        printf( "%lld\n", ans );
    }
    return 0;
}