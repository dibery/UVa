#include<stdio.h>

int main()
{
    int t, size;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%*s %*s %d", &size );
        bool sys = true;
        long long int field[ size ][ size ];

        for( int i = 0; i < size; ++i )
            for( int j = 0; j < size; ++j )
                scanf( "%lld", &field[ i ][ j ] );
        for( int i = 0; i < size && sys; ++i )
            for( int j = 0; j < size && sys; ++j )
                if( field[ i ][ j ] < 0 || field[ i ][ j ] != field[ size-i-1 ][ size-j-1 ] )
                    sys = false;
        printf( "Test #%d: %s\n", i, sys? "Symmetric." : "Non-symmetric." );
    }

	return 0;
}
