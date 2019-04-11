#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
bool brd[ 1000 ][ 1000 ] = { { false } };
int dist[ 1000 ][ 1000 ]= { { 0 } };

int main()
{
    for( int h, w, bomb, bh, bw, eh, ew; scanf( "%d %d", &h, &w ) && h; )
    {
        queue<int> bfs;

        memset( brd, false, sizeof( brd ) );
        memset( dist, 0, sizeof( dist ) );
        for( scanf( "%d", &bomb ); bomb--; )
        {
            int loc, num, n;
            scanf( "%d %d", &loc, &num );
            while( num-- )
                scanf( "%d", &n ), brd[ loc ][ n ] = true;
        }
        scanf( "%d %d %d %d", &bh, &bw, &eh, &ew );

        dist[ bh ][ bw ] = 1;
        for( bfs.push( bh * 1000 + bw ); !bfs.empty(); bfs.pop() )
            for( int H = bfs.front() / 1000, W = bfs.front() % 1000, i = H-1; i <= H+1; ++i )
                for( int j = W-1; j <= W+1; ++j )
                    if( i >= 0 && i < h && j >= 0 && j < w && i == H ^ j == W && !brd[ i ][ j ] && !dist[ i ][ j ] )
                    {
                        bfs.push( i * 1000 + j );
                        dist[ i ][ j ] = dist[ H ][ W ] + 1;
                    }
        printf( "%d\n", --dist[ eh ][ ew ] );
    }
}
