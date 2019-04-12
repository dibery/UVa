#include<cstdio>

int main()
{
    int size, game = 0;

    while( scanf( "%d", &size ) && size )
    {
        int num[ size ], ans[ size ];

        for( int i = 0; i < size; ++i )
            scanf( "%d", ans+i );
        for( printf( "Game %d:\n", ++game ); ; )
        {
            int A = 0, B = 0;
            bool used[ size ];

            for( int i = 0; i < size; ++i )
                scanf( "%d", num+i ), used[ i ] = false;
            if( !*num )
                break;

            for( int i = 0; i < size; ++i )
                if( num[ i ] == ans[ i ] )
                    ++A, used[ i ] = true;
            for( int i = 0; i < size; ++i )
                if( num[ i ] != ans[ i ] )
                    for( int j = 0; j < size; ++j )
                        if( num[ i ] == ans[ j ] && !used[ j ] )
                        {
                            ++B;
                            used[ j ] = true;
                            break;
                        }
            printf( "    (%d,%d)\n", A, B );
        }
    }
}
