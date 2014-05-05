#include<cstdio>
#include<algorithm>
using namespace std;
const char *Suit = "CDSH", *Face = "23456789TJQKA", *Dir = "SWNE";
inline int dir( char a )
{
    if( a == 'N' )
        return 0;
    if( a == 'E' )
        return 1;
    if( a == 'S' )
        return 2;
    return 3;
}
inline int suit( char a )
{
    if( a == 'C' )
        return 0;
    if( a == 'D' )
        return 1;
    if( a == 'S' )
        return 2;
    return 3;
}
inline int face( char a )
{
    if( a <= '9' && a >= '2' )
        return a-'1';
    if( a == 'T' )
        return 9;
    if( a == 'J' )
        return 10;
    if( a == 'Q' )
        return 11;
    if( a == 'K' )
        return 12;
    return 13;
}


int main()
{
    char dealer, in[ 3 ];
    int hand[ 4 ][ 13 ] = { 0 };

    while( scanf( "%c%*c", &dealer ) && dealer != '#' )
    {
        int init = dir( dealer )+2;
        for( int i = 1; i <= 26; ++i )
        {
            scanf( "%2s", in );
            hand[ ( i+init ) % 4 ][ ( i - 1 ) / 4 ] = 13 * suit( *in ) + face( in[ 1 ] ) - 1;
        }
        scanf( "%*c" );
        for( int i = 27; i <= 52; ++i )
        {
            scanf( "%2s", in );
            hand[ ( i+init ) % 4 ][ ( i - 1 ) / 4 ] = 13 * suit( *in ) + face( in[ 1 ] ) - 1;
        }
        for( int i = 0; i < 4; ++i )
            sort( hand[ i ], hand[ i ]+13 );
        for( int i = 0; i < 4; ++i )
        {
            printf( "%c:", Dir[ i ] );
            for( int k = 0; k < 13; ++k )
                printf( " %c%c", Suit[ hand[ i ][ k ] / 13 ], Face[ hand[ i ][ k ] % 13 ] );
            puts( "" );
        }
        scanf( "%*c" );
    }
    return 0;
}
