#include<cstdio>
#include<cmath>

int prime[ 1000000 ] = { 2 }, n, all = 1, i;
bool isprime[ 1000001 ] = { false };

bool check( int &n, int *prime, int &all )
{
    int bound = sqrt( n );
    for( int i = 0; prime[ i ] <= bound; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    for( i = 3; i <= 1000000; i += 2 )
        if( check( i, prime, all ) )
            prime[ all++ ] = i, isprime[ i ] = true;

    while( scanf( "%d", &n ) && n )
    {
        for( i = 0; i < all; ++i )
            if( isprime[ n - prime[ i ] ] )
                break;
        printf( "%d = %d + %d\n", n, prime[ i ], n - prime[ i ] );
    }

    return 0;
}
