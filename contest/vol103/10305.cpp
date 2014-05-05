#include<cstdio>
#include<set>
using namespace std;

int main()
{
    int task, order, before, after;

    while( scanf( "%d %d", &task, &order ) && ( task || order ) )
    {
        set<int> topo[ task+1 ], print;
        int out = 0;
        for( int i = 1; i <= task; ++i )
            print.insert( i );
        for( int i = 0; i < order; ++i )
        {
            scanf( "%d %d", &before, &after );
            topo[ after ].insert( before );
        }
        while( !print.empty() )
            for( int i = 1; i <= task; ++i )
                if( topo[ i ].empty() && print.find( i ) != print.end() )
                {
                    for( int j = 1; j <= task; ++j )
                        topo[ j ].erase( i );
                    printf( "%d%c", i, ++out == task? '\n' : ' ' );
                    print.erase( i );
                }
        for( int i = 1; i <= task; ++i )
            topo[ i ].clear();
    }

    return 0;
}
