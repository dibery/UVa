#include<cstdio>
#include<cmath>
int t, in, ans[ 1000001 ] = { 0 }, factor[ 1000001 ] = { 0 }, prime[ 78500 ] = { 2 }, counter, size = 0;
double bound;
bool isprime( int in )
{
    int bound = sqrt( double( in ) );
    for( int i = 1; i <= size && prime[ i ] <= bound; ++i )
        if( in % prime[ i ] == 0 )
            return false;
    return true;
}
int find_fact( int num )
{
    int fact = 1, bound = sqrt( double( num ) );
    for( int i = 0; num != 1 && prime[ i ] <= bound; ++i )
    {
        int tmp = 0;
        while( num % prime[ i ] == 0 )
        {
            num /= prime[ i ];
            ++tmp;
        }
        fact *= tmp+1;
    }
    if( num > 1 )
        fact <<= 1;
    return fact;
}

int main()
{
    scanf( "%d", &t );
    for( int i = 3; i < 1000000; i += 2 )
        if( isprime( i ) )
            prime[ ++size ] = i;
    for( int i = 1; i <= 1000000; ++i )
        factor[ i ] = find_fact( i );
    for( int i = 1; i <= 1000000; ++i )
        ans[ i ] = factor[ ans[ i-1 ] ] <= factor[ i ] ? i : ans[ i-1 ];

    while( t-- )
    {
        scanf( "%d", &in );
        printf( "%d\n", ans[ in ] );
    }

    return 0;
}
