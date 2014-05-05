#include<cstdio>
#include<cstdlib>
#include<cstring>

int main()
{
    char in[ 40 ], out[ 35 ];
    int len, now = -1;
    bool one;
    memset( out, 0, sizeof( out ) );
    while( scanf( "%s", in ) && strcmp( in, "~" ) )
        if( !strcmp( in, "#" ) )
        {
            printf( "%d\n", strtol( out, NULL, 2 ) );
            memset( out, 0, sizeof( out ) );
            now = -1;
        }
        else
        {
            if( ( len = strlen( in ) ) == 1 )
                one = true;
            else if( len == 2 )
                one = false;
            else
                for( int i = 0; i < len-2; ++i )
                    sprintf( out+(++now), "%c", one? '1' : '0' );
        }

	return 0;
}