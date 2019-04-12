#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>

bool stat[ 500 ][ 30000 ];

int main()
{
	for( int stu, grp, size[ 500 ]; scanf( "%d %d", &stu, &grp ) && stu; )
	{
		bool vis[ 500 ] = { false }, adj[ 500 ][ 500 ] = { { false } }, sick[ 30000 ] = { true };
		std::queue<int> bfs;
		std::vector<int> list[ 500 ];
		memset( stat, 0, sizeof( stat ) );

		for( int i = 0; i < grp; ++i )
		{
			scanf( "%d", size + i );
			for( int j = 0, n; j < size[ i ]; ++j )
			{
				scanf( "%d", &n );
				stat[ i ][ n ] = true;
				list[ i ].push_back( n );
			}
		}

		for( int i = 0; i < grp; ++i )
			for( int j = i + 1; j < grp; ++j )
				for( int k = 0; k < list[ i ].size() && !adj[ i ][ j ]; ++k )
					if( stat[ j ][ list[ i ][ k ] ] )
						adj[ i ][ j ] = adj[ j ][ i ] = true;

		for( int i = 0; i < grp; ++i )
			if( *stat[ i ] )
			{
				bfs.push( i );
				vis[ i ] = true;
				for( int j = 0; j < list[ i ].size(); ++j )
					sick[ list[ i ][ j ] ] = true;
			}
		for( ; !bfs.empty(); bfs.pop() )
			for( int i = 0; i < grp; ++i )
				if( !vis[ i ] && adj[ bfs.front() ][ i ] )
				{
					vis[ i ] = true;
					bfs.push( i );
					for( int j = 0; j < list[ i ].size(); ++j )
						sick[ list[ i ][ j ] ] = true;
				}
		printf( "%lu\n", std::count( sick, sick + stu, true ) );
	}
}
