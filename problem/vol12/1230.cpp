#include<cstdio>

int main()
{
    int base, exp, mod, cal[ 32 ], ans, t;
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d %d", &base, &exp, &mod );
        if( base == 0 || mod == 1 )
            puts( "0" );
        else if( base == 1 || exp == 0 )
            puts( "1" );
        else if( exp == 1 )
            printf( "%d\n", base % mod );
        else
        {
            *cal = ans = 1;
            cal[ 1 ] = base % mod;
            for( int i = 2; i < 32; ++i )
                cal[ i ] = ( cal[ i-1 ] * cal[ i-1 ] ) % mod;
            for( int i = 0; i < 31; ++i )
                if( 1 << i & exp )
                    ans = ( ans * cal[ i+1 ] ) % mod;
            printf( "%d\n", ans );
        }
    }

	return 0;
}