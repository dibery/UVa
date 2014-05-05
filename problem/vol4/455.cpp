#include<cstdio>
#include<cstring>
bool is_period( char *str, int period )
{
    for( int i = 0; str[ i ]; ++i )
        if( str[ i ] != str[ i % period ] )
            return false;
    return true;
}

int main()
{
    int t, len, period;
    char str[ 81 ];
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%s", str );
        len = strlen( str );
        for( period = 1; period <= len; ++period )
            if( len % period == 0 )
                if( is_period( str, period ) )
                    break;
        printf( "%d\n", period );
        if( t )
            puts( "" );
    }

	return 0;
}