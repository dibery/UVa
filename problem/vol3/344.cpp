#include<stdio.h>
inline int cov( char a )
{
    if( a == 'I' )
        return 0;
    if( a == 'V' )
        return 1;
    if( a == 'X' )
        return 2;
    if( a == 'L' )
        return 3;
    return 4;
}

int main()
{
    char *hundred[] = { "", "C" }, *ten[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" }, *one[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" }, tmp[ 10 ];
    int n, ans[ 101 ][ 5 ] = { 0 };

    for( int a = 1; a <= 100; ++a )
    {
        sprintf( tmp, "%s%s%s ", hundred[ a/100 ], ten[ (a/10)%10 ], one[ a%10 ] );
        for( int i = 0; i < 5; ++i )
            ans[ a ][ i ] = ans[ a-1 ][ i ];
        for( int i = 0; tmp[ i ] != ' '; ++i )
            ++ans[ a ][ cov( tmp[ i ] ) ];
    }
    while( scanf( "%d", &n ) && n )
        printf( "%d: %d i, %d v, %d x, %d l, %d c\n", n, ans[ n ][ 0 ], ans[ n ][ 1 ], ans[ n ][ 2 ], ans[ n ][ 3 ], ans[ n ][ 4 ] );

    return 0;
}
