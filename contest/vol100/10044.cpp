#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, book, man;
	string Erdos = "Erdos, P.", nouse;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d\n", &book, &man );
		map<string,int> id;
		vector<vector<int> > adj;
		queue<int> bfs;

		for( int i = 0; i < book; ++i )
		{
			vector<string> dict;

			for( string s1, s2; cin >> s1 >> s2; )
			{
				char c = s2[ s2.size() - 1 ];
				if( *--s1.end() == ':' )
					break;
				s2.erase( --s2.end() );
				dict.push_back( s1 + " " + s2 );
				if( c == ':' )
					break;
			}
			getline( cin, nouse );

			for( int i = 0; i < dict.size(); ++i )
				if( id.find( dict[ i ] ) == id.end() )
				{
					id.insert( make_pair( dict[ i ], id.size() ) );
					adj.push_back( vector<int>() );
				}
			for( int i = 0; i < dict.size(); ++i )
				for( int j = i + 1; j < dict.size(); ++j )
				{
					adj[ id[ dict[ i ] ] ].push_back( id[ dict[ j ] ] );
					adj[ id[ dict[ j ] ] ].push_back( id[ dict[ i ] ] );
				}
		}

		int ans[ 5000 ] = { 0 };
		fill( ans, ans + id.size(), INT_MAX );
		ans[ id[ Erdos ] ] = 0;

		for( bfs.push( id[ Erdos ] ); !bfs.empty(); bfs.pop() )
			for( auto& i: adj[ bfs.front() ] )
				if( ans[ i ] == INT_MAX )
					ans[ i ] = ans[ bfs.front() ] + 1, bfs.push( i );

		printf( "Scenario %d\n", n );
		for( string query; man-- && getline( cin, query ); )
			if( id.find( query ) == id.end() || ans[ id[ query ] ] == INT_MAX )
				printf( "%s infinity\n", query.c_str() );
			else
				printf( "%s %d\n", query.c_str(), ans[ id[ query ] ] );
	}
}
