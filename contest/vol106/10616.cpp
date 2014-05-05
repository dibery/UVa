#include<cstdio>
#include<cstring>

int main()
{
    int n, query, mod, take, num[ 201 ], s = 0;
    long long int dp[ 201 ][ 11 ][ 21 ];

    while( scanf( "%d %d", &n, &query ) && n )
    {
        for( int i = 1; i <= n; ++i )
            scanf( "%d", num+i );
        printf( "SET %d:\n", ++s );
        for( int i = 1; i <= query; ++i )
        {
            scanf( "%d %d", &mod, &take );
            memset( dp, 0, sizeof( dp ) );
            for( int k = 1; k <= n; ++k )
                dp[ k ][ 1 ][ ( ( num[ k ] % mod ) + mod ) % mod ] = 1;
            for( int b = 1; b <= take; ++b )
                for( int a = b; a <= n; ++a )
                    for( int c = 0; c < mod; ++c )
                        dp[ a ][ b ][ c ] += dp[ a-1 ][ b-1 ][ ( c + mod - num[ a ] % mod ) % mod ] + dp[ a-1 ][ b ][ c ];
            printf( "QUERY %d: %lld\n", i, dp[ n ][ take ][ 0 ] );
        }
    }

	return 0;
}