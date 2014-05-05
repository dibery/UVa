#include<cstdio>
#include<vector>
using namespace std;
vector<int>order[ 1000001 ];

int main()
{
	int num, query, in, serial;

	while( scanf( "%d %d", &num, &query ) == 2 )
	{
		for( int i = 1; i <= num; ++i )
			scanf( "%d", &in ), order[ in ].push_back( i );
		for( int i = 0; i < query; ++i )
			scanf( "%d %d", &serial, &in ), printf( "%d\n", order[ in ].size() >= serial? order[ in ][ serial-1 ] : 0 );
		for( int i = 1; i <= 1000000; ++i )
			order[ i ].clear();
	}

	return 0;
}
