#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
class node
{
public:
    int id, time;
    bool operator()( const node &a, const node &b ) { return a.time != b.time? a.time > b.time : a.id > b.id; }
    node( int i = 0, int t = 0 ) { id = i, time = t; }
};

int main()
{
    int query[ 1000 ] = { 0 }, period[ 1000 ] = { 0 }, in = -1, t;
    char cmd[ 20 ];
    priority_queue<node,vector<node>,node>argus;

    while( scanf( "%s", cmd ) && *cmd != '#' )
        scanf( "%d %d", &query[ in ], &period[ ++in ] );
    scanf( "%d", &t );
    for( int i = 0; i <= in; ++i )
        for( int j = 1; j <= t; ++j )
            argus.push( node( query[ i ], period[ i ] * j ) );
    for( int i = 0; i < t; ++i )
        printf( "%d\n", argus.top().id ), argus.pop();

	return 0;
}