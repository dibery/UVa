#include<cstdio>

int main()
{
    int in;
    long long int ans[ 42 ] = { 0, 1, 5, 11 };
    for( int i = 4; i < 42; ++i )
        ans[ i ] = 2*ans[ i-3 ] + 4*ans[ i-2 ] + ans[ i-1 ];
    scanf( "%*s" );
	while( scanf( "%d", &in ) != EOF )
        printf( "%lld\n", ans[ in ] );

	return 0;
}