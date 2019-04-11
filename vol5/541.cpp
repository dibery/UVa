#include<cstdio>

int main()
{
    int size;

    while( scanf( "%d", &size ) && size )
    {
        bool row[ 100 ] = { false }, col[ 100 ] = { false };
        int field[ 100 ][ 100 ] = { 0 }, R = 0, C = 0, oddR, oddC;
        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
            {
                scanf( "%d", field[ i ]+j );
                row[ i ] ^= field[ i ][ j ];
                col[ j ] ^= field[ i ][ j ];
            }
        for( int i = 0; i < size; ++i )
        {
            R += row[ i ];
            C += col[ i ];
            if( row[ i ] )
                oddR = i+1;
            if( col[ i ] )
                oddC = i+1;
        }
        if( !R && !C )
            puts( "OK" );
        else if( R == 1 && C == 1 )
            printf( "Change bit (%d,%d)\n", oddR, oddC );
        else
            puts( "Corrupt" );
    }

    return 0;
}
