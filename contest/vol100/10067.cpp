#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
	int t, begin, end, a, b, c, d, ban[ 10000 ] = { 0 }, size;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d %d %d", &a, &b, &c, &d );
		begin = a*1000 + b*100 + c*10 + d;
		scanf( "%d %d %d %d", &a, &b, &c, &d );
		end = a*1000 + b*100 + c*10 + d;
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d %d %d", &a, &b, &c, &d );
			ban[ i ] = a*1000 + b*100 + c*10 + d;
		}
		int dist[ 10000 ] = { 0 };
		queue<int> bfs;
		if( find( ban, ban+size, begin ) == ban+size && find( ban, ban+size, end ) == ban+size && begin != end )
			bfs.push( begin );
		for( ; !bfs.empty() && !dist[ end ]; bfs.pop() )
		{
			char tmp[ 5 ];
			sprintf( tmp, "%04d", bfs.front() );
			for( int i = 0; i < 4; ++i )
			{
				tmp[ i ] = ( tmp[ i ] + 1 - '0' ) % 10 + '0';
				int n = atoi( tmp );
				if( n != begin && !dist[ n ] && find( ban, ban+size, n ) == ban+size )
					bfs.push( n ), dist[ n ] = dist[ bfs.front() ] + 1;
				tmp[ i ] = ( tmp[ i ] + 8 - '0' ) % 10 + '0';
				n = atoi( tmp );
				if( n != begin && !dist[ n ] && find( ban, ban+size, n ) == ban+size )
					bfs.push( n ), dist[ n ] = dist[ bfs.front() ] + 1;
				tmp[ i ] = ( tmp[ i ] + 1 - '0' ) % 10 + '0';
			}
		}
		printf( "%d\n", begin == end? 0 : dist[ end ]? dist[ end ] : -1 );
	}
}
