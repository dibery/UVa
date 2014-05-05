#include<cstdio>
inline int find( int a )
{
    int sum = 1;
    for( int i = 2; i <= a; ++i )
        if( a % i == 0 )
            sum += i;
    return sum;
}

int main()
{
    int ans[ 1001 ], n, t = 0, factor;
    for( int i = 0; i <= 1000; ++i )
        ans[ i ] = -1;
    for( int i = 1; i <= 1000; ++i )
    {
        factor = find( i );
        if( factor <= 1000 )
            ans[ factor ] = i;
    }

    while( scanf( "%d", &n ) && n )
        printf( "Case %d: %d\n", ++t, ans[ n ] );

	return 0;
}