#include<cstdio>
#include<cstring>
const int inapplicable = -1;
void find( int index, int *forward, bool *visited, int *candicate, int &maxdep, int curdep )
{
    candicate[ index ] = curdep == 1? 0 : inapplicable;
    visited[ index ] = true;
    if( maxdep < curdep )
        maxdep = curdep;
    if( !visited[ forward[ index ] ] )
        find( forward[ index ], forward, visited, candicate, maxdep, curdep+1 );
    visited[ index ] = false;
}

int main()
{
    int test, size, *forward, tmp, *dep, *candicate, ans;
    bool *sent, *visited;
    scanf( "%d", &test );

    for( int t = 1; t <= test; ++t )
    {
        scanf( "%d", &size );
        forward = new int[ size+1 ];
        dep = new int[ size+1 ];
        sent = new bool[ size+1 ];
        visited = new bool[ size+1 ];
        candicate = new int[ size+1 ];
        for( int i = 0; i <= size; ++i )
            sent[ i ] = visited[ i ] = false;
        memset( candicate, 0, sizeof( candicate ) );
        for( int i = 0; i < size; ++i )
        {
            scanf( "%d", &tmp );
            scanf( "%d", forward+tmp );
            sent[ forward[ tmp ] ] = true;
        }
        for( int i = 1; i <= size; ++i )
            if( !sent[ i ] )
            {
                tmp = 0;
                find( i, forward, visited, candicate, tmp, 1 );
                candicate[ i ] = tmp;
            }
        for( int i = 1; i <= size; ++i )   //for self-loop
            if( candicate[ i ] != inapplicable && sent[ i ] )
            {
                tmp = 0;
                find( i, forward, visited, candicate, tmp, 1 );
                candicate[ i ] = tmp;
            }
        tmp = 0;
        for( int i = 1; i <= size; ++i )
            if( tmp < candicate[ i ] )
            {
                tmp = candicate[ i ];
                ans = i;
            }
        printf( "Case %d: %d\n", t, ans );
        delete[] forward;
        delete[] sent;
        delete[] visited;
        delete[] dep;
        delete[] candicate;
    }
    return 0;
}
