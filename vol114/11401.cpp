#include<cstdio>
long long int ans[ 1000001 ] = { 0 }, in;

int main()
{
    for( long long int i = 4; i <= 1000000; ++i )
        ans[ i ] = ( i-3 + ( i+1 ) % 2 ) * ( ( i+1 ) / 2 - 1 ) / 2 + ans[ i-1 ];
    while( scanf( "%lld", &in ) && in >= 3 )
        printf( "%lld\n", ans[ in ] );

	return 0;
}