#include<cstdio>
#include<cstring>

int main()
{
    int size, in, bin[ 65536 ], now, i;

    while( scanf( "%d", &size ) != EOF )
    {
        memset( bin, 0, sizeof( bin ) );
        now = 0;
        for( i = 0; i < size; ++i )
        {
            scanf( "%d", &in );
            ++bin[ in ];
        }
        if( size % 2 == 1 )
        {
            for( i = 0; now < (size+1) / 2; ++i )
                now += bin[ i ];
            printf( "%d %d 1\n", i-1, bin[ i-1 ] );
        }
        else
        {
            for( i = 0; now < size / 2; ++i )
                now += bin[ i ];
            if( now == size / 2 )
            {
                int s = bin[ i-1 ], init = i-1;
                printf( "%d ", i-1 );
                while( !bin[ i ] )
                    ++i;
                printf( "%d %d\n", s + bin[ i ], i-init+1 );
            }
            else
                printf( "%d %d 1\n", i-1, bin[ i-1 ] );
        }
    }
    return 0;
}
