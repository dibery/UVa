#include<cstdio>
#include<cstdlib>

int main()
{
    char in[ 11 ];

    while( gets( in ) )
        if( *in == '-' )
            break;
        else if( in[ 1 ] == 'x' )
            printf( "%d\n", strtol( in, NULL, 16 ) );
        else
            printf( "0x%X\n", strtol( in, NULL, 10 ) );

	return 0;
}