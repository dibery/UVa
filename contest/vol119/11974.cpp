#include<cstdio>
#include<queue>
using namespace std;
const int section = -1;
int bfs( int *mask, int init, int switches )
{
    int dist = 0;
    bool visited[ 65536 ] = { false };
    queue<int> state;
    state.push( init );
    state.push( section );
    while( !state.empty() )
    {
        if( state.front() > 0 )
            visited[ state.front() ] = true;
        if( state.front() == 0 )
            return dist;
        else if( state.front() == -1 )
        {
            ++dist;
            if( state.size() > 1 )
                state.push( section );
        }
        else if( dist > switches )
            return -1;
        else
            for( int i = 0; i < switches; ++i )
                if( !visited[ state.front() ^ mask[ i ] ] )
                    state.push( state.front() ^ mask[ i ] );
        state.pop();
    }
    return -1;
}

int main()
{
    int t, light, switches, tmp;
    scanf( "%d", &t );

    for( int i = 1; i <= t; ++i )
    {
        scanf( "%d %d", &light, &switches );
        int mask[ 100 ] = { 0 }, init = ( 1 << light ) - 1, dist;
        for( int i = 0; i < switches; ++i )
            for( int j = 0; j < light; ++j )
            {
                scanf( "%d", &tmp );
                mask[ i ] |= tmp << j;
            }
        dist = bfs( mask, init, switches );
        if( dist == -1 )
            printf( "Case %d: IMPOSSIBLE\n", i );
        else
            printf( "Case %d: %d\n", i, dist );
    }

    return 0;
}
