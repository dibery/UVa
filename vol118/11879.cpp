#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
inline int borrow( char a )
{
    if( a > 47 )
        return 0;
    if( a > 37 )
        return 1;
    if( a > 27 )
        return 2;
    if( a > 17 )
        return 3;
    if( a > 7 )
        return 4;
    return 5;
}

int main()
{
    char in[ 102 ] = { 0 };

    while( gets( in ) && strcmp( in, "0" ) )
    {
        int len = strlen( in ), i = 0;
        char *end = in+len;
        std::reverse( in, end );
        while( len > 18 )
        {
            in[ i+1 ] -= 5 * ( in[ i ] - '0' );
            for( char *a = in+i+1; a != end; ++a )
                if( *a < '0' )
            {
                a[ 1 ] -= borrow( a[ 0 ] );
                a[ 0 ] += borrow( a[ 0 ] ) * 10;
            }
            in[ i++ ] = 0;
            --len;
        }
        std::reverse( in+i, end );
        puts( strtoll( in+i, NULL, 10 ) % 17? "0" : "1" );
    }
    return 0;
}
