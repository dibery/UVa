#include<bits/stdc++.h>
using namespace std;

map<string,string> solve;
queue<string> bfs;

void insert( string& s, int x, int offset, char action )
{
	string S = s;
	swap( S[ x ], S[ x + offset ] );
	if( solve.find( S ) == solve.end() )
	{
		bfs.push( S );
		solve[ S ] = solve[ s ] + action;
	}
}

int main()
{
	int t;
	string query = "12345678x";
	solve[ query ] = "";

	for( bfs.push( query ); !bfs.empty(); bfs.pop() )
	{
		string& s = bfs.front();
		int x = s.find( 'x' );
		if( x % 3 < 2 )
			insert( s, x, 1, 'l' );
		if( x % 3 > 0 )
			insert( s, x, -1, 'r' );
		if( x >= 3 )
			insert( s, x, -3, 'd' );
		if( x < 6 )
			insert( s, x, 3, 'u' );
	}
	for( auto& s: solve )
		reverse( s.second.begin(), s.second.end() );

	cin >> t;
	cin.get();
	cin.get();
	while( t-- && getline( cin, query ) )
	{
		if( t )
			cin.get();
		query = regex_replace( query, regex( " " ), "" );
		if( solve.find( query ) != solve.end() )
			cout << solve[ query ] << endl;
		else
			cout << "unsolvable\n";
		if( t )
			cout << endl;
	}
}
