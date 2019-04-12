#include<cstdio>

int main()
{
    int size, number[ 100 ], t = 0;

    while( scanf( "%d", &size ) != EOF )
    {
        bool rep = false, sum[ 20001 ] = { false };
        for( int i = 0; i < size; ++i )
            scanf( "%d", number+i );
        if( *number < 1 )
            rep = true;
        for( int i = 1; i < size && !rep; ++i )
            if( number[ i ] <= number[ i-1 ] )
                rep = true;
        for( int i = 0; i < size && !rep; ++i )
            for( int j = i; j < size && !rep; ++j )
                if( sum[ number[ i ] + number[ j ] ] )
                    rep = true;
                else
                    sum[ number[ i ] + number[ j ] ] = true;
        printf( "Case #%d: It is%s a B2-Sequence.\n\n", ++t, rep? " not" : "" );
    }
}