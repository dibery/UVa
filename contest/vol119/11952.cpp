#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
inline bool only_one( char *str )
{
    for( int i = 0; str[ i ]; ++i )
        if( str[ i ] != '1' )
            return false;
    return true;
}

int main()
{
    int t;
    char a[ 100005 ], b[ 100005 ], sum[ 100005 ];
    scanf( "%d", &t );

    while( t-- )
    {
        int base = 0;
        scanf( "%s + %s = %s", a, b, sum );
        for( int i = 0; a[ i ]; ++i )
            base = std::max( base, a[ i ] - '0' );
        for( int i = 0; b[ i ]; ++i )
            base = std::max( base, b[ i ] - '0' );
        for( int i = 0; sum[ i ]; ++i )
            base = std::max( base, sum[ i ] - '0' );
        if( base )
            ++base;
        for( ; base && base <= 18 && strtol( a, NULL, base ) + strtol( b, NULL, base ) != strtol( sum, NULL, base ); ++base );
        if( base <= 18 && base )
            printf( "%d\n", base );
        else if( !base )
            puts( "2" );
        else//
            if( only_one( a ) && only_one( b ) && only_one( sum ) )
                printf( "%s\n", strlen( a ) + strlen( b ) == strlen( sum ) ? "1" : "0" );
            else
                puts( "0" );
    }

    return 0;
}