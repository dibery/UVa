#include<cstdio>
#include<cmath>

int prime[ 500 ] = { 1, 2 }, n, all = 2, i, cum[ 1001 ] = { 0 }, c;
bool isprime[ 1001 ] = { false, true, true };

bool check( int &n, int *prime, int &all )
{
    int bound = sqrt( n );
    for( int i = 1; prime[ i ] <= bound; ++i )
        if( n % prime[ i ] == 0 )
            return false;
    return true;
}

int main()
{
    for( i = 3; i <= 1000; i += 2 )
        if( check( i, prime, all ) )
            prime[ all++ ] = i, isprime[ i ] = true;
    for( int i = 1; i <= 1000; ++i )
        cum[ i ] = cum[ i-1 ] + ( isprime[ i ]? 1 : 0 );

    while( scanf( "%d %d", &n, &c ) != EOF )
    {
        printf( "%d %d:", n, c );
        if( cum[ n ] % 2 == 1 )
            if( c * 2 - 1 >= cum[ n ] )
                for( int i = 0; prime[ i ] <= n && i < all; ++i )
                    printf( " %d", prime[ i ] );
            else
                for( int i = cum[ n ]/2 - ( 2*c-1 ) / 2; i <= cum[ n ]/2 + ( 2*c-1 ) / 2; ++i )
                    printf( " %d", prime[ i ] );
        else//
            if( c * 2 >= cum[ n ] )
                for( int i = 0; prime[ i ] <= n && i < all; ++i )
                    printf( " %d", prime[ i ] );
            else
                for( int i = 0, offset = ( cum[ n ] - 2*c ) / 2; i < 2*c; ++i )
                    printf( " %d", prime[ i+offset ] );
        puts( "\n" );
    }

    return 0;
}
