#include<cstdio>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int cmd, act, arg;

    while( scanf( "%d", &cmd ) != EOF )
    {
        bool s = true, q = true, pq = true;
        stack<int> S;
        queue<int> Q;
        priority_queue<int> PQ;
        for( int i = 0; i < cmd; ++i )
        {
            scanf( "%d %d", &act, &arg );
            if( act == 1 )
            {
                if( s )
                    S.push( arg );
                if( q )
                    Q.push( arg );
                if( pq )
                    PQ.push( arg );
            }
            else
            {
                if( s )
                    if( S.empty() || S.top() != arg )
                        s = false;
                    else
                        S.pop();
                if( q )
                    if( Q.empty() || Q.front() != arg )
                        q = false;
                    else
                        Q.pop();
                if( pq )
                    if( PQ.empty() || PQ.top() != arg )
                        pq = false;
                    else
                        PQ.pop();
            }
        }
        if( s + q + pq > 1 )
            puts( "not sure" );
        else if( s + q + pq == 0 )
            puts( "impossible" );
        else if( s )
            puts( "stack" );
        else if( q )
            puts( "queue" );
        else
            puts( "priority queue" );
    }

	return 0;
}