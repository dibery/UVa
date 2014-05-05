#include<cstdio>
#include<cstring>
char str[ 1000000 ];
inline bool is_period( int &period )
{
    for( int i = 0; str[ i ]; ++i )
        if( str[ i ] != str[ i % period ] )
            return false;
    return true;
}

int main()
{
    register int len, period;

    while( gets( str ) && strcmp( str, "." ) )
    {
        len = strlen( str );
        for( period = 1; period <= len; ++period )
            if( len % period == 0 )
                if( is_period( period ) )
                    break;
        printf( "%d\n", len / period );
    }

	return 0;
}