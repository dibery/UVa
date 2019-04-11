#include<cstdio>
#include<cstdlib>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
class node
{
	public:
		int val, next, len;
		node( int v ) { val = v; next = -1; len = 1; }
};

int main()
{
	int t;
	char num[ 15 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		int M = 0, pos, vis = 0;
		vector<node> LIS;

		while( gets( num ) && *num )
			LIS.push_back( node( atoi( num ) ) );

		for( int i = LIS.size() - 1; i >= 0; --i )
			for( int j = i+1; j < LIS.size(); ++j )
				if( LIS[ j ].val > LIS[ i ].val && LIS[ j ].len >= LIS[ i ].len )
					LIS[ i ].next = j, LIS[ i ].len = LIS[ j ].len + 1;
		for( int i = LIS.size() - 1; i >= 0; --i )
			if( M < LIS[ i ].len )
				M = LIS[ i ].len, pos = i;

		printf( "Max hits: %d\n", M );
		while( pos != -1 )
			printf( "%d\n", LIS[ pos ].val ), pos = LIS[ pos ].next;
		if( t ) puts( "" );
	}
}
