#include<cstdio>
int t, n;
long long int ans[ 1000001 ] = { 0 };

int main()
{
    for( long long int i = 4; i <= 1e6; ++i )
        ans[ i ] = ans[ i-1 ] + ( ( i+1 ) % 2 + i-3 ) * ( ( i-1 ) / 2 ) / 2;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d", &n );
        printf( "%lld\n", ans[ n ] );
    }

	return 0;
}