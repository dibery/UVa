#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>

int main()
{
    char in[ 1001 ];

    while( gets( in ) && strcmp( in, "0" ) )
    {
        char tmp[ 3 ] = { 0 };
        int len = strlen( in );
        strncpy( tmp, in, len % 2? 1 : 2 );
        printf( "%d", int( sqrt( atoi( tmp ) ) ) );
        for( int i = 0; i < (len-1) / 2; ++i )
            putchar( '0' );
        puts( "" );
    }
}
