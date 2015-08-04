#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int in, ask, t;

	for( scanf( "%d", &t ); t--; )
	{
		vector<int> box;
		queue<int> query, num;
		int index = 0;
		scanf( "%d %d", &in, &ask );
		for( int i = 0, q; i < in; ++i )
			scanf( "%d", &q ), num.push( q );
		for( int i = 0, q; i < ask; ++i )
			scanf( "%d", &q ), query.push( q );
		while( !query.empty() )
		{
			for( ; box.size() != query.front(); num.pop() )
				box.insert( lower_bound( box.begin(), box.end(), num.front() ), num.front() );
			for( ; query.front() == box.size(); query.pop() )
				printf( "%d\n", box[ index++ ] );
		}
		printf( t? "\n" : "" );
	}
}
