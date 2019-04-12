#include<cstdio>
#include<cstdlib>

int main()
{
    int t;
    register int i, k;
    char str[ 31 ];
    scanf( "%d\n", &t );

    for( i = 1; i <= t; ++i )
    {
        gets( str );
        for( k = 0; str[ k ]; ++k )
            if( str[ k ] == 'A' )
                str[ k ] = '0';
            else if( str[ k ] == 'C' )
                str[ k ] = '1';
            else if( str[ k ] == 'G' )
                str[ k ] = '2';
            else
                str[ k ] = '3';
        printf( "Case %d: (%d:%lld)\n", i, k, strtoll( str, NULL, 4 ) );
    }

	return 0;
}