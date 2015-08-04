#include<bits/stdc++.h>
#define N 10000
using namespace std;

void show( string* name, int path[][ 1001 ], int v, int speed, bool first = false )
{
	if( path[ v ][ speed ] != -1 )
		show( name, path, path[ v ][ speed ] % N, path[ v ][ speed ] / N );
	cout << name[ v ] << ( first? '\n' : ' ' );
}

int main()
{
	int edge, w;
	bool first = true;
	string from, to;

	while( scanf( "%d", &edge ) == 1 )
	{
		map<string,int> id;
		list<int> adj[ 500 ][ 500 ];
		int path[ 500 ][ 1001 ];
		queue<int> bfs;

		if( !first )
			puts( "" );
		else
			first = false;
		memset( path, -1, sizeof( path ) );

		for( int e = 0; e < edge; ++e )
		{
			cin >> from >> to >> w;
			if( id.find( from ) == id.end() )
				id.insert( make_pair( from, id.size() ) );
			if( id.find( to ) == id.end() )
				id.insert( make_pair( to, id.size() ) );
			adj[ id[ from ] ][ id[ to ] ].push_back( w );
			adj[ id[ to ] ][ id[ from ] ].push_back( w );
		}

		cin >> from >> to;

		if( id.find( from ) != id.end() && id.find( to ) != id.end() )
			bfs.push( id[ from ] );
		while( !bfs.empty() && bfs.front() % N != id[ to ] )
		{
			int now = bfs.front();
			bfs.pop();
			for( size_t i = 0; i < id.size(); ++i )
				for( list<int>::iterator j = adj[ now % N ][ i ].begin(); j != adj[ now % N ][ i ].end(); ++j )
					if( path[ i ][ *j ] == -1 && *j >= now / N )
					{
						bfs.push( *j * N + i );
						path[ i ][ *j ] = now;
					}
		}

		string inv[ 500 ];
		for( map<string,int>::iterator i = id.begin(); i != id.end(); ++i )
			inv[ i->second ] = i->first;
		if( bfs.empty() )
			puts( "No valid route." );
		else
			show( inv, path, bfs.front() % N, bfs.front() / N, true );
	}
}
