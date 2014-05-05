#include<cstdio>
inline int trans( int a )
{
    while( a % 5 == 0 )
        a = a / 5 * 8;
    return a;
}

int main()
{
    int in, ans[ 10001 ] = { 1 };
    for( int i = 1; i <= 10000; ++i )
        ans[ i ] = ans[ i-1 ] * trans( i ) % 10;

    while( scanf( "%d", &in ) != EOF )
        printf( "%5d -> %d\n", in, ans[ in ] );

    return 0;
}
