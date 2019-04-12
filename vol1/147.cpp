#include<cstdio>
const int coin[] = { 0, 1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000 };

int main()
{
    int dec, flo;
    long long int ans[ 6001 ][ 12 ] = { 0 };
    for( int i = 0; i <= 11; ++i )
        ans[ 0 ][ i ] = 1;
    for( int i = 1; i <= 6000; ++i )
        for( int j = 1; j <= 11; ++j )
            if( i >= coin[ j ] )
                ans[ i ][ j ] = ans[ i-coin[ j ] ][ j ] + ans[ i ][ j-1 ];
            else
                ans[ i ][ j ] = ans[ i ][ j-1 ];

    while( scanf( "%d.%d", &dec, &flo ) && dec+flo )
        printf( "%3d.%02d%17lld\n", dec, flo, ans[ dec*20 + flo/5 ][ 11 ] );

	return 0;
}