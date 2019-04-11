#include<cstdio>

int main()
{
    int test;
    scanf( "%d", &test );

    while( test-- )
    {
        int size, num[ 1000 ], sum = 0, above = 0;
        double ave;
        scanf( "%d", &size );
        for( int i = 0; i < size; ++i )
        {
            scanf( "%d", num+i );
            sum += num[ i ];
        }
        ave = double( sum ) / size;
        for( int i = 0; i < size; ++i )
            if( num[ i ] > ave )
                ++above;
        printf( "%.3lf%%\n", double( above ) / size * 100 );
    }
    return 0;
}
