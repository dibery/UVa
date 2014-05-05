#include<cstdio>
#include<cmath>
const int max = 18409206;

int n, all = 1, twin[ 100001 ];
bool notprime[ max+1 ] = { false };

int main()
{
    for( int i = 3; i <= 4290; i += 2 )
        if( !notprime[ i ] )
            for( int j = 3; i * j < max; j += 2 )
                notprime[ i * j ] = true;
    for( int i = 3; i < max; i += 2 )
        if( !notprime[ i ] && !notprime[ i+2 ] )
            twin[ all++ ] = i;

    while( scanf( "%d", &n ) != EOF )
        printf( "(%d, %d)\n", twin[ n ], twin[ n ]+2 );

    return 0;
}
