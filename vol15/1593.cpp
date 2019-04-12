#include<iostream>
#include<iomanip>
#include<sstream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	vector<vector<string> > dict;
	int M = 0;

	for( string s; getline( cin, s ); )
	{
		dict.push_back( vector<string>() );
		for( stringstream ss( s ); ss >> s; )
			dict.back().push_back( s );
		M = max( M, int( dict.back().size() ) );
	}

	vector<int> size( M, 0 );
	for( int i = 0; i < M; ++i )
		for( auto& j: dict )
			size[ i ] = max( size[ i ], j.size() > i? int( j[ i ].size() ) : 0 );

	for( auto& i: dict )
		for( int j = 0; j < i.size(); ++j )
			if( j == i.size() - 1 )
				cout << i[ j ] << endl;
			else
				cout << setw( size[ j ] ) << left << i[ j ] << ' ';
}
