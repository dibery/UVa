#include<cstdio>
int array[ 10000 ];

int main()
{
    int size;

    while( scanf( "%d", &size ) && size )
    {
        scanf( "%d", array );
        int max = *array < 0? 0 : *array, current = *array < 0? 0 : *array;
        for( int i = 1; i < size; ++i )
        {
            scanf( "%d", array+i );
            current += array[ i ];
            if( max < current )
                max = current;
            if( current < 0 )
                current = 0;
        }
        if( max )
            printf( "The maximum winning streak is %d.\n", max );
        else
            puts( "Losing streak." );
    }
    return 0;
}
