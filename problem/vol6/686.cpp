#include<cstdio>
#include<cmath>

int prime[ 3520 ] = { 2 }, n, all = 1, i;
bool isprime[ 32768 ] = { false, false, true };

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
    for( i = 3; i <= 32768; i += 2 )
        if( check( i, prime, all ) )
            prime[ all++ ] = i, isprime[ i ] = true;

    while( scanf( "%d", &n ) && n )
    {
        int sol = 0;
        for( i = 0; i < all && prime[ i ]*2 <= n; ++i )
            if( isprime[ n - prime[ i ] ] )
                ++sol;
        printf( "%d\n", sol );
    }

    return 0;
}
