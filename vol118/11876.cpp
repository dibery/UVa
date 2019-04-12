#include<cstdio>
#include<algorithm>
using namespace std;
int val[ 1000001 ] = { 1 };
int prime[ 150000 ] = { 2 }, size = 1;
bool notprime[ 1000001 ] = { true, true, false };
int time( int& up, int down )
{
    int t = 0;
    while( up % down == 0 )
        up /= down, ++t;
    return t;
}
int nod( int n )
{
    int ans = 1;
    for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
        if( n % prime[ i ] == 0 )
            ans *= time( n, prime[ i ] ) + 1;
    if( n != 1 )
      ans <<= 1;
    return ans;
}

int main()
{
    int t, from, to;
    for( int i = 3; i < 1000; i += 2 )
        if( !notprime[ i ] )
            for( int j = i; i*j < 1000000; j += 2 )
                notprime[ i*j ] = true;
    for( int i = 3; i < 1000000; i += 2 )
        if( !notprime[ i ] )
            prime[ size++ ] = i;
    for( int i = 1; i <= 1000000; ++i )
        val[ i ] = val[ i-1 ] + nod( val[ i-1 ] );
    scanf( "%d", &t );
    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d %d", &from, &to );
        printf( "Case %d: %d\n", i, upper_bound( val, val+1000001, to ) - lower_bound( val, val+1000001, from ) );
    }
    return 0;
}
