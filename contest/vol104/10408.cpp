#include<cstdio>
#include<set>
using namespace std;

class node
{
	public:
		node( int d, int u ) { up = u; down = d; } // u/d
		bool operator< ( const node& rhs ) const { return up*rhs.down < rhs.up*down; }
		int up, down;
};

int main()
{
	set<node> all;
	int down, seq;
	for( int d = 1; d <= 1000; ++d )
		for( int n = 1; n <= d; ++n )
			all.insert( node( d, n ) );
	while( scanf( "%d %d", &down, &seq ) == 2 )
	{
		set<node>::iterator it = all.begin();
		for( ; seq; ++it )
			if( it->down <= down )
				--seq;
		--it;
		printf( "%d/%d\n", it->up, it->down );
	}
}
