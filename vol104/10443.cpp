#include<cstdio>
char field[ 102 ][ 102 ] = { 0 }, tmp[ 102 ][ 102 ];
int row, col, t, day;
bool contain( int i, int j, char x )
{
    for( int m = i-1; m <= i+1; ++m )
        for( int n = j-1; n <= j+1; ++n )
            if( m == i ^ n == j )
                if( field[ m ][ n ] == x )
                    return true;
    return false;
}

int main()
{
    scanf( "%d", &t );

    while( t-- )
    {
        scanf( "%d %d %d", &row, &col, &day );
        for( int i = 1; i <= row; ++i )
            scanf( "%s", field[ i ] + 1 );
        while( day-- )
        {
            for( int i = 1; i <= row; ++i )
                for( int j = 1; j <= col; ++j )
                    if( field[ i ][ j ] == 'R' && contain( i, j, 'P' ) )
                        tmp[ i ][ j ] = 'P';
                    else if( field[ i ][ j ] == 'P' && contain( i, j, 'S' ) )
                        tmp[ i ][ j ] = 'S';
                    else if( field[ i ][ j ] == 'S' && contain( i, j, 'R' ) )
                        tmp[ i ][ j ] = 'R';
                    else
                        tmp[ i ][ j ] = field[ i ][ j ];
            for( int i = 1; i <= row; ++i )
                for( int j = 1; j <= col; ++j )
                    field[ i ][ j ] = tmp[ i ][ j ];
        }
        for( int i = 1; i <= row; ++i )
            printf( "%s\n", field[ i ] + 1 );
        if( t )
            puts( "" );
    }

    return 0;
}
