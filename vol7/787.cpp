#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<cctype>
using namespace std;
int numlen( int *array )
{
    for( int i = 499; i >= 0; --i )
        if( array[ i ] )
            return i;
    return 0;
}

class Num
{
public:
    Num();
    char min[ 500 ], max[ 500 ], in[ 6 ];
    int num, digit;
    bool mp, Mp;
}  *array = NULL;

Num::Num()
{
    for( int i = 0; i < 500; ++i )
        min[ i ] = max[ i ] = 0;
    mp = Mp = true;
}

bool cmp( char *a, char *b )
{
    if( a[ 0 ] == '-' )
        if( b[ 0 ] == '-' )
            if( strlen( a ) > strlen( b ) )
                return true;
            else if( strlen( a ) < strlen( b ) )
                return false;
            else
                return ( strcmp( a, b ) > 0 );
        else
            return true;
    else if( a[ 0 ] != '-' )
        if( b[ 0 ] != '-' )
            if( strlen( a ) > strlen( b ) )
                return false;
            else if( strlen( a ) < strlen( b ) )
                return true;
            else
                return ( strcmp( a, b ) < 0 );
        else
            return false;
}

char *findmax( char *a, char *b, char *c )
{
    char *tmp[ 3 ] = { a, b, c };
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 2; ++j )
            if( cmp( tmp[ j ], tmp[ j+1 ] ) )
                swap( tmp[ j ], tmp[ j+1 ] );
    //sort( tmp, tmp+2, cmp );
    return tmp[ 0 ];
}

char *findmin( char *a, char *b, char *c )
{
    char *tmp[ 3 ] = { a, b, c };
    for( int i = 0; i < 3; ++i )
        for( int j = 0; j < 2; ++j )
            if( cmp( tmp[ j ], tmp[ j+1 ] ) )
                swap( tmp[ j ], tmp[ j+1 ] );
    //sort( tmp, tmp+2, cmp );
    return tmp[ 2 ];
}

int main()
{
    int offset = -1;
    char in[ 10 ];
    while( cin >> in )
    {
        if( !array )
            array = new Num[ 100 ];
        if( strcmp( in, "-999999" ) )
        {
            strcpy( array[ ++offset ].in, in );
            array[ offset ].num = atoi( in );
            reverse( array[ offset ].in, array[ offset ].in+strlen( array[ offset ].in ) );
            array[ offset ].digit = strlen( array[ offset ].in );
            if( array[ offset ].in[ array[ offset ].digit ] == '-' )
                --array[ offset ].digit;
        }
        else
        {
            strcpy( array[ offset ].min, array[ offset ].in );
            strcpy( array[ offset ].max, array[ offset ].in );

            if( array[ offset ].num < 0 )
                array[ offset ].min[ strlen( array[ offset ].min )-1 ] = 0;
            if( array[ offset ].num < 0 )
                array[ offset ].max[ strlen( array[ offset ].max )-1 ] = 0;
            if( array[ offset ].num < 0 )
                array[ offset ].mp = array[ offset ].Mp = false; //the last one

            for( int i = offset-1; i >= 0; --i )
            {
                bool ap = true, bp = true, cp = true;   //it, min, max is positive
                char a[ 600 ] = { 0 }, b[ 600 ] = { 0 }, c[ 600 ] = { 0 };  //to choose which to use
                int k, I[ 500 ] = { 0 }, M[ 500 ] = { 0 }, m[ 500 ] = { 0 };

                for( k = 0; isdigit( array[ i ].in[ k ] ); ++k )
                    I[ k ] = array[ i ].in[ k ] - '0'; //rev
                if( array[ i ].in[ strlen( array[ i ].in )-1 ] == '-' )
                    ap = false; //itself
                if( !ap )
                    *a = '-';
                for( int x = numlen( I ); x >= 0; --x )
                    a[ x+( ap? 0 : 1 ) ] = I[ x ]+'0';
                reverse( a+( ap? 0 : 1 ), a+strlen( a ) );  //a b c is normal order

                for( k = 0; isdigit( array[ i+1 ].min[ k ] ); ++k )
                    m[ k ] = ( array[ i+1 ].min[ k ] - '0' ) * abs( array[ i ].num );
                for( k = 0; k < 500; ++k )
                    if( m[ k ] > 9 )
                    {
                        m[ k+1 ] += m[ k ] / 10;
                        m[ k ] %= 10;
                    }   //rev
                if( ( array[ i ].num < 0 ^ !array[ i+1 ].mp ) && array[ i ].num )
                    bp = false; //min
                if( !bp )
                    *b = '-';
                for( int x = numlen( m ); x >= 0; --x )
                    b[ x+( bp? 0 : 1 ) ] = m[ x ]+'0';
                reverse( b+( bp? 0 : 1 ), b+strlen( b ) );

                for( k = 0; isdigit( array[ i+1 ].max[ k ] ); ++k )
                    M[ k ] = ( array[ i+1 ].max[ k ] - '0' ) * abs( array[ i ].num );
                for( k = 0; k < 500; ++k )
                    if( M[ k ] > 9 )
                    {
                        M[ k+1 ] += M[ k ] / 10;
                        M[ k ] %= 10;
                    }   //rev
                if( ( array[ i ].num < 0 ^ !array[ i+1 ].Mp ) && array[ i ].num )
                    cp = false; //max
                if( !cp )
                    *c = '-';
                for( int x = numlen( M ); x >= 0; --x )
                    c[ x+( cp? 0 : 1 ) ] = M[ x ]+'0';
                reverse( c+( cp? 0 : 1 ), c+strlen( c ) );

                char *max = findmax( a, b, c ), *min = findmin( a, b, c );  //normal order, item determined
                strcpy( array[ i ].min, min+( *min == '-'? 1 : 0 ) );
                strcpy( array[ i ].max, max+( *max == '-'? 1 : 0 ) );
                reverse( array[ i ].min, array[ i ].min+strlen( array[ i ].min ) );
                reverse( array[ i ].max, array[ i ].max+strlen( array[ i ].max ) ); //copy content
                if( *max == '-' )
                    array[ i ].Mp = false;
                if( *min == '-' )
                    array[ i ].mp = false;  //the sign
            }

            for( int i = 0; i <= offset; ++i )
            {
                if( !array[ i ].Mp )
                    array[ i ].max[ strlen( array[ i ].max ) ] = '-';
                reverse( array[ i ].max, array[ i ].max+strlen( array[ i ].max ) );
            }

            char out[ 600 ] = { 0 };
            strcpy( out, array[ offset ].max );
            for( int i = offset-1; i >= 0; --i )
                if( cmp( out, array[ i ].max ) )
                    strcpy( out, array[ i ].max );
            cout << out << endl;

            offset = -1; //reset
            delete[] array;
            array = NULL;
        }
    }

    return 0;
}
