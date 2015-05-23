#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	for( int node, begin, end, query; scanf( "%d", &node ) && node; )
	{
		bool adj[ 500 ][ 500 ] = { { false } };

		while( scanf( "%d", &begin ) && begin )
			while( scanf( "%d", &end ) && end )
				adj[ begin-1 ][ end-1 ] = true;
		for( int i = 0; i < node; ++i )
			for( int j = 0; j < node; ++j )
				for( int k = 0; k < node; ++k )
					adj[ j ][ k ] |= adj[ j ][ i ] && adj[ i ][ k ];

		for( scanf( "%d", &query ); query--; puts( "" ) )
		{
			vector<int> cant;

			scanf( "%d", &begin );
			--begin;
			for( int i = 0; i < node; ++i )
				if( !adj[ begin ][ i ] )
					cant.push_back( i );

			printf( "%u", cant.size() );
			for( int i = 0; i < cant.size(); ++i )
				printf( " %d", cant[ i ] + 1 );
		}
	}
}
