#include<bits/stdc++.h>
using namespace std;

template<typename edge>
struct graph
{
	graph( int SIZE )
	{
		adj = new map<int,edge>[ size = SIZE ];
	}
	~graph()
	{
		delete[] adj;
	}
	void add( int u, int v, edge d = 1, bool bi = false )
	{
		adj[ u ][ v ] = d;
		if( bi )
			adj[ v ][ u ] = d;
	}
	vector<vector<edge>> apsp()
	{
		vector<vector<edge>> result;
		result.reserve( size );
		for( int i = 0; i < size; ++i )
			result.emplace_back( size, INT_MAX );
		for( int i = 0; i < size; ++i )
			result[ i ][ i ] = 0;
		for( int i = 0; i < size; ++i )
			for( auto& j: adj[ i ] )
				result[ i ][ j.first ] = j.second;
		for( int m = 0; m < size; ++m )
			for( int b = 0; b < size; ++b )
				for( int e = 0; e < size; ++e )
					if( result[ b ][ m ] != INT_MAX && result[ m ][ e ] != INT_MAX )
						result[ b ][ e ] = min( result[ b ][ e ], result[ b ][ m ] + result[ m ][ e ] );
		return result;
	}
	map<int, edge>* adj;
	int size;
};

bool judge( vector<vector<int>> a, vector<vector<int>> b, int size, int A, int B )
{
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			if( a[ i ][ j ] != INT_MAX && b[ i ][ j ] > a[ i ][ j ] * A + B )
				return false;
	return true;
}

int main()
{
	for( int n, A, B; scanf( "%d", &n ) && n; )
	{
		graph<int> g( n ), g2( n );
		char str[ 1000 ];

		for( int i = 0, to; i < n && !scanf( "%*d" ); ++i )
			for( stringstream ss( gets( str ) ); ss >> to; )
				g.add( i, --to );
		for( int i = 0, to; i < n && !scanf( "%*d" ); ++i )
			for( stringstream ss( gets( str ) ); ss >> to; )
				g2.add( i, --to );
		scanf( "%d %d", &A, &B );
		puts( judge( g.apsp(), g2.apsp(), n, A, B )? "Yes" : "No" );
	}
}
