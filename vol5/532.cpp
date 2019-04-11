#include<cstdio>
#include<queue>
#define A bfs.front()/10000
#define B bfs.front()/100%100
#define C bfs.front()%100
using namespace std;
inline bool ok( int m, int n, int o, int i, int j, int k, int a, int b, int c )
{
    int t = int( m == i ) + int( n == j ) + int( o == k );
    return t == 2 && m >= 0 && m < a && n >= 0 && n < b && o >= 0 && n < c;
}

int main()
{
    int x, y, z, t;
    char maze[ 30 ][ 30 ][ 31 ] = { 0 };

    while( scanf( "%d %d %d", &x, &y, &z ) && x )
    {
        queue<int> bfs;
        bool found = false;
        int dist[ 30 ][ 30 ][ 30 ] = { 0 };
        for( int i = 0; i < x; ++i )
            for( int j = 0; j < y; ++j )
                scanf( "%s", maze[ i ][ j ] );
        for( int i = 0; i < x && bfs.empty(); ++i )
            for( int j = 0; j < y && bfs.empty(); ++j )
                for( int k = 0; k < z && bfs.empty(); ++k )
                    if( maze[ i ][ j ][ k ] == 'S' )
                        bfs.push( i * 10000 + j * 100 + k );
        for( ; !bfs.empty() && !found; bfs.pop() )
            for( int m = A - 1; m <= A + 1; ++m )
                for( int n = B - 1; n <= B + 1; ++n )
                    for( int o = C - 1; o <= C + 1; ++o )
                        if( ok( m, n, o, A, B, C, x, y, z ) )
							if( maze[ m ][ n ][ o ] == '.' )
							{
								bfs.push( m*10000 + n*100 + o );
								dist[ m ][ n ][ o ] = dist[ A ][ B ][ C ] + 1;
								maze[ m ][ n ][ o ] = '#';
							}
							else if( maze[ m ][ n ][ o ] == 'E' && !found )
								found = true, printf( "Escaped in %d minute(s).\n", dist[ A ][ B ][ C ] + 1 );
        if( !found )
            puts( "Trapped!" );
    }
}
