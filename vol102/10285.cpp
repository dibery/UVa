#include<stdio.h>

int sizei, sizej, i, j, length = 0, counter; //variables

int finishpath( int path[ 200 ][ 200 ] , int copy[ 200 ][ 200 ] )
{
    for( i = 1; i <= sizei; i++ )
        for( j = 1; j <= sizej; j++ )
            if( path[ i ][ j ] != -214748364 )
                return 0;   //there are still some skiing

    return 3;   //all have been eliminated
}

int main()
{
    int test;
    char name[ 10000 ];
    scanf( "%d", &test );
    while( test-- )
    {
        scanf( "%s %d %d\n", name, &sizei, &sizej );
        int path[ 200 ][ 200 ] = { 0 }; //array
        int copy[ 200 ][ 200 ] = { 0 }; //array

        for( counter = 0; counter <= sizei+1; counter++ )    //the "wall", making it easier to count steps
        {
            path[ counter ][ 0 ] = -214748364;
            copy[ counter ][ 0 ] = -214748364;
            path[ counter ][ sizej+1 ] = -214748364;
            copy[ counter ][ sizej+1 ] = -214748364;
        }
        for( counter = 0; counter <= sizej+1; counter++ )    //the "wall", making it easier to count steps
        {
            path[ 0 ][ counter ] = -214748364;
            copy[ 0 ][ counter ] = -214748364;
            path[ sizei+1 ][ counter ] = -214748364;
            copy[ sizei+1 ][ counter ] = -214748364;
        }

        for( i = 1; i <= sizei; i++ ) //input
            for( j = 1; j <= sizej; j++ )
            {
                scanf( "%d ", &path[ i ][ j ]);
                copy[ i ][ j ] = path[ i ][ j ];
            }

        for( length = 0; finishpath( path, copy ) == 0; length++ )
        {
            for( i = 1; i <= sizei; i++ )   //find the highest point among others
            {
                for( j = 1; j <= sizej; j++ )
                {
                    if( path[ i ][ j ] >= path[ i+1 ][ j ] && path[ i ][ j ] >= path[ i-1 ][ j ]
                            && path[ i ][ j ] >= path[ i ][ j+1 ] && path[ i ][ j ] >= path[ i ][ j-1 ] )
                        copy[ i ][ j ] = -214748364;    //the highest becomes the lowest
                }
            }

            for( i = 1; i <= sizei; i++ )   //copy the result to real array
                for( j = 1; j <= sizej; j++ )
                    path[ i ][ j ] = copy[ i ][ j ];
        }

        printf( "%s: %d\n", name, length ); //output
    }

    return 0;
}
