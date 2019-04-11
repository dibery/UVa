#include<cstdio>
#include<cmath>
#include<algorithm>

const int max = 10000000;
int n, prime[ max / 2 ] = { 2 }, all = 0, call[ 5 ];
bool notprime[ max+1 ] = { true, true }, found;
void search( int n, int quant, int index )
{
    call[ quant ] = n;
    if( quant == 1 && !notprime[ n ] )
        found = true;
    if( quant == 1 )
        return;
    for( int i = index; i >= 0 && !found && prime[ i ] < n; --i )
        search( n - prime[ i ], quant-1, std::lower_bound( prime, prime+all, n - prime[ i ] ) - prime - 1 );
    if( found )
        return;
    call[ quant ] = 0;
}

int main()
{
    for( int i = 3; i <= 3162; i += 2 )
        if( !notprime[ i ] )
            for( int j = 3; i * j < max; j += 2 )
                notprime[ i * j ] = true;
    prime[ all++ ] = 2;
    for( int i = 3; i < max; i += 2 )
        if( !notprime[ i ] )
            prime[ all++ ] = i;

    while( scanf( "%d", &n ) != EOF )
    {
        found = false;
        search( n, 4, std::lower_bound( prime, prime+all, n ) - prime - 1 );
        if( found )
            printf( "%d %d %d %d\n", call[ 4 ] - call[ 3 ], call[ 3 ] - call[ 2 ], call[ 2 ] - call[ 1 ], call[ 1 ] );
        else
            puts( "Impossible." );
    }

    return 0;
}
