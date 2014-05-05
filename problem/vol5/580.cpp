#include<cstdio>

int main()
{
    int ans[ 31 ] = { 0, 0, 0 }, in, pow2[ 31 ] = { 1 };
    for( int i = 1; i < 31; ++i )
        pow2[ i ] = pow2[ i-1 ] << 1;
    for( int i = 3; i < 31; ++i )
        ans[ i ] = ans[ i-1 ] + ans[ i-2 ] + ans[ i-3 ] + pow2[ i-3 ];

    while( scanf( "%d", &in ) && in )
        printf( "%d\n", ans[ in ] );

	return 0;
}