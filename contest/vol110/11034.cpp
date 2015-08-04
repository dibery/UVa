#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int t, len, qnt, car;
	char pos[ 10 ];

	for( scanf( "%d", &t ); t--; )
	{
		queue<int> left, right;
		int cross = 0;

		scanf( "%d %d", &len, &qnt );
		len *= 100;
		for( int i = 0; i < qnt; ++i )
		{
			scanf( "%d %s", &car, pos );
			( *pos == 'l'? left : right ).push( car );
		}

		while( !left.empty() || !right.empty() )
		{
			for( int load = 0; !left.empty() && load + left.front() <= len; left.pop() )
				load += left.front();
			++cross;
			if( left.empty() && right.empty() )
				break;
			for( int load = 0; !right.empty() && load + right.front() <= len; right.pop() )
				load += right.front();
			++cross;
		}
		printf( "%d\n", cross );
	}
}
