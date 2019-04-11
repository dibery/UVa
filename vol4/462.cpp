#include<iostream>
#include<cctype>
#include<cstring>
#include<cstdio>
using namespace std;
const int spade = 0, heart = 1, diamond = 2, club = 3;
const char Suit[] = { "SHDC" };
inline int suit( char a )
{
    if( a == 'S' )
        return spade;
    else if( a == 'H' )
        return heart;
    else if( a == 'D' )
        return diamond;
    return club;
}
inline int point( char a )
{
    if( a == 'J' )
        return 1;
    else if( a == 'Q' )
        return 2;
    else if( a == 'K' )
        return 3;
    else if( a == 'A' )
        return 4;
    return 0;
}

int main()
{
    int hcp, distrib[ 4 ], stop[ 4 ], bonus, key[ 4 ];
    char card[ 13 ][ 3 ];

    while( true )
    {
        hcp = bonus = 0;
        memset( distrib, 0, sizeof( distrib ) );
        memset( stop, 0, sizeof( stop ) );
        memset( key, 0, sizeof( key ) );
        for( int i = 0; i < 13; ++i )
            if( scanf( "%s", card[ i ] ) != 1 )
                return 0;
        for( int i = 0; i < 13; ++i )
            ++distrib[ suit( card[ i ][ 1 ] ) ];
        for( int i = 0; i < 13; ++i )
            hcp += point( card[ i ][ 0 ] );
        for( int i = 0; i < 13; ++i )
            if( card[ i ][ 0 ] == 'K' && distrib[ suit( card[ i ][ 1 ] ) ] > 1 || card[ i ][ 0 ] == 'Q' && distrib[ suit( card[ i ][ 1 ] ) ] > 2 || card[ i ][ 0 ] == 'A' )
                ++stop[ suit( card[ i ][ 1 ] ) ];
        for( int i = 0; i < 13; ++i )
            if( card[ i ][ 0 ] == 'J' && distrib[ suit( card[ i ][ 1 ] ) ] < 4 || card[ i ][ 0 ] == 'Q' && distrib[ suit( card[ i ][ 1 ] ) ] < 3 || card[ i ][ 0 ] == 'K' && distrib[ suit( card[ i ][ 1 ] ) ] < 2 )
                --hcp;
        for( int i = 0; i < 4; ++i )
            if( distrib[ i ] == 2 )
                ++bonus;
            else if( distrib[ i ] == 1 || !distrib[ i ] )
                bonus += 2;
        if( hcp + bonus < 14 )
            puts("PASS");
        else if( hcp >= 16 && stop[ 0 ] && stop[ 1 ] && stop[ 2 ] && stop[ 3 ] )
            puts("BID NO-TRUMP");
        else
        {
            int max = -1;
            for( int i = 0; i < 4; ++i )
                if( max < distrib[ i ] )
                    max = distrib[ i ];
            for( int i = 0; i < 4; ++i )
                if( distrib[ i ] == max )
                {
                    printf( "BID %c\n", Suit[ i ] );
                    break;
                }
        }
    }
    return 0;
}
