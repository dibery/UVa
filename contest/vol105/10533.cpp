#include<cstdio>
#include<cmath>
bool table[ 1000000 ] = { false }, is_prime[ 1000000 ] = { false };
int prime_num[ 169 ] = { 0 }, put = -1, out[ 1000000 ] = { 0 };
inline int check( int n )
{
    int bound = sqrt( n );
    for( int i = 0; prime_num[ i ] && prime_num[ i ] <= bound; ++i )
        if( n % prime_num[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    int t;
    scanf( "%d", &t );

    for( int i = 2; i < 1000; ++i )
        if( check( i ) )
            prime_num[ ++put ] = i;
    for( int i = 2; i < 1000000; ++i )
        is_prime[ i ] = check( i );
    for( int i = 1, tmp, sum; i < 1000000; ++i )
    {
        tmp = i;
        sum = 0;
        while( tmp )
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        table[ i ] = is_prime[ sum ] && is_prime[ i ];
    }
    for( int i = 1; i < 1000000; ++i )
        out[ i ] = out[ i-1 ] + table[ i ];

    while( t-- )
    {
        int ans = 0, l, h;
        scanf( "%d %d", &l, &h );
        printf( "%d\n", out[ h ] - out[ l-1 ] );
    }

    return 0;
}
