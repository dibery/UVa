#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int size, n[ 750 ] = { 0 }, mini[ 750 ], tmp[ 750 ], l = 0;

	while( scanf( "%d", &size ) == 1 )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", mini+i );
		for( int t = 1; t < size; ++t, l = 0 )
		{
			for( int i = 0; i < size; ++i )
				scanf( "%d", n+i );
			sort( n, n+size );
			sort( mini, mini+l );

			int pos[ 750 ] = { 0 };
			priority_queue< long long int, vector<long long int>, greater<long long int> > use;
			for( int i = 0; i < size; ++i )
				use.push( ( mini[ i ] + n[ 0 ] ) * 1000 + i );
			for( int i = 0; i < size; ++i )
			{
				int now = use.top() % 1000;
				tmp[ l++ ] = mini[ now ] + n[ pos[ now ]++ ];
				use.pop();
				use.push( ( mini[ now ] + n[ pos[ now ] ] ) * 1000 + now );
			}
			copy( tmp, tmp+size, mini );
		}
		for( int i = 0; i < size; ++i )
			printf( "%d%c", mini[ i ], i == size-1? '\n' : ' ' );
	}
}
