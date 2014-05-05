#include<cstdio>

int main()
{
    int exp[ 10 ];

    while( scanf( "%d %d %d %d %d %d %d %d %d", exp+8, exp+7, exp+6, exp+5, exp+4, exp+3, exp+2, exp+1, exp ) != EOF )
    {
        int i = 8;
        for( ; i; --i )
            if( exp[ i ] )
                if( i != 1 )
                    if( exp[ i ] != 1 && exp[ i ] != -1 )
                    {
                        printf( "%dx^%d", exp[ i ], i );
                        --i;
                        break;
                    }
                    else if( exp[ i ] == 1 )
                    {
                        printf( "x^%d", i );
                        --i;
                        break;
                    }
                    else
                    {
                        printf( "-x^%d", i );
                        --i;
                        break;
                    }
                else//
                    if( exp[ i ] != 1 && exp[ i ] != -1 )
                {
                    printf( "%dx", exp[ i ] );
                    --i;
                    break;
                }
                else if( exp[ i ] == 1 )
                {
                    printf( "x" );
                    --i;
                    break;
                }
                else
                {
                    printf( "-x" );
                    --i;
                    break;
                }
        if( i == 0 && exp[ 1 ] == 0 )
        {
            printf( "%d\n", *exp );
            continue;
        }
        for( ; i > 1; --i )
            if( exp[ i ] < 0 )
                if( exp[ i ] != -1 )
                    printf( " - %dx^%d", -exp[ i ], i );
                else
                    printf( " - x^%d", i );
            else if( exp[ i ] > 0 )
                if( exp[ i ] != 1 )
                    printf( " + %dx^%d", exp[ i ], i );
                else
                    printf( " + x^%d", i );
        if( exp[ 1 ] < 0 && i == 1 )
            if( exp[ 1 ] != -1 )
                printf( " - %dx", -exp[ 1 ] );
            else
                printf( " - x" );
        else if( exp[ 1 ] > 0 && i == 1 )
            if( exp[ 1 ] != 1 )
                printf( " + %dx", exp[ 1 ] );
            else
                printf( " + x" );
        if( *exp < 0 )
            printf( " - %d", -*exp );
        else if( *exp > 0 )
            printf( " + %d", *exp );
        puts( "" );
    }
    return 0;
}
