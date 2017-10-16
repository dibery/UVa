#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<string,bool> ans;

vector<string> split_str( string s )
{
	vector<string> v;
	for( char c: s )
		if( v.empty() || c != v.back().back() )
			v.emplace_back( 1, c );
		else
			v.back() += c;
	return v;
}

string join_str( vector<string>& v, int skip = -1 )
{
	string s;
	for( int i = 0; i < v.size(); ++i )
		if( i != skip )
			s += v[ i ];
	return s;
}

int dfs( string s )
{
	vector<string> v = split_str( s );
	if( ans.find( s ) != ans.end() )
		return ans[ s ];
	for( int i = 0; i < v.size(); ++i )
		if( v[ i ].size() > 1 && dfs( join_str( v, i ) ) )
			return ans[ s ] = true;
	return ans[ s ] = false;
}

int main()
{
	int t;
	string s;
	ans[ "" ] = true;
	for( cin >> t; t-- && cin >> s; )
		cout << dfs( s ) << endl;
}
