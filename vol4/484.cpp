#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
class node
{
public:
    node( int );
    int val, freq;
    bool operator==( node );
};
node::node( int v )
{
    val = v;
    freq = 1;
}
bool node::operator==( node a ) { return a.val == val; }

int main()
{
    vector<node> all;
    vector<node>::iterator it;
    int n;

    while( scanf( "%d", &n ) != EOF )
        if( ( it = find( all.begin(), all.end(), node( n ) ) ) == all.end() )
            all.push_back( node( n ) );
        else
            ++(*it).freq;
    for( it = all.begin(); it != all.end(); ++it )
        printf( "%d %d\n", (*it).val, (*it).freq );

	return 0;
}