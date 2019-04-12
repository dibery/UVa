#include<cstdio>
#include<algorithm>

void dfs( bool adj[ 26 ][ 26 ], bool visited[ 26 ], int index )
{
	visited[ index ] = true;
	for( int i = 0; i < 26; ++i )
		if( adj[ index ][ i ] && !visited[ i ] )
			dfs( adj, visited, i );
}

int main()
{
	int t;
	char str[ 100 ];
	
	for( scanf( "%d", &t ); t--; )
	{
		bool adj[ 26 ][ 26 ] = { false }, exist[ 26 ] = { false }, visited[ 26 ] = { false };
		int tree = 0, acorn = 0;

		while( scanf( "%s", str ) )
			if( *str == '(' )
				adj[ str[ 1 ]-'A' ][ str[ 3 ]-'A' ] = adj[ str[ 3 ]-'A' ][ str[ 1 ]-'A' ] = true;
			else if( *str != '*' )
			{
				for( int i = 0; str[ i ]; ++i )
					if( str[ i ] != ',' )
						exist[ str[ i ]-'A' ] = true;
				break;
			}

		for( int i = 0; i < 26; ++i )
			if( !visited[ i ] && exist[ i ] )
				if( std::count( adj[ i ], adj[ i ]+26, true ) == 0 )
					visited[ i ] = true, ++acorn;
				else
					dfs( adj, visited, i ), ++tree;
		printf( "There are %d tree(s) and %d acorn(s).\n", tree, acorn );
	}
}
