#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

int main()
{
    int base;
    char n[ 1001 ], m[ 10 ];

    while( scanf( "%d", &base ) && base )
    {
        scanf( "%s %s", n, m );
        int mod = strtol( m, NULL, base ), len = strlen( n ), ans = 0, i = 0;
        char print[ 1000 ] = { 0 };
        for( int i = 0; n[ i ]; ++i )
            n[ i ] -= '0';
        for( int i = 0; i < len; ++i )
        {
            ans *= base;
            ans += n[ i ];
            ans %= mod;
        }
        if( ans == 0 )
        {
            puts( "0" );
            continue;
        }
        while( ans )
        {
            print[ i++ ] = ans % base + '0';
            ans /= base;
        }
        std::reverse( print, print+i );
        puts( print );
    }

	return 0;
}