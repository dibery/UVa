#include<cstdio>
#include<list>
using namespace std;
int DFS( list<int> *adj, int index, bool *visited )
{
    int back = 1;
    visited[ index ] = true;
    for( list<int>::iterator it = adj[ index ].begin(); it != adj[ index ].end(); ++it )
        if( !visited[ *it ] )
            back += DFS( adj, *it, visited );
    return back;
}

int main()
{
    int stu, query, t = 0, a, b;

    while( scanf( "%d %d", &stu, &query ) && stu )
    {
        list<int> same[ stu+1 ];
        bool visited[ 50000 ] = { false };
        int ans = stu;
        for( int i = 0; i < query; ++i )
        {
            scanf( "%d %d", &a, &b );
            if( a == b )
                continue;
            same[ a ].push_back( b );
            same[ b ].push_back( a );
        }
        for( int i = 1; i <= stu; ++i )
            if( !visited[ i ] )
                ans -= DFS( same, i, visited ) - 1;
        printf( "Case %d: %d\n", ++t, ans );
    }

    return 0;
}
