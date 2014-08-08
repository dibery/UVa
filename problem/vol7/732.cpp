#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

void dfs( stack<char>& s, string::iterator f, string::iterator fe, string::iterator t, string::iterator te, string op = "" )
{
	if( f == fe && t == te )
	{
		for( size_t i = 0; i < op.size(); ++i )
			cout << op[ i ] << ( i == op.size() - 1? '\n' : ' ' );
		return;
	}
	if( f != fe )
	{
		s.push( *f );
		dfs( s, next( f ), fe, t, te, op + "i" );
		s.pop();
	}
	if( !s.empty() && s.top() == *t )
	{
		s.pop();
		dfs( s, f, fe, next( t ), te, op + "o" );
		s.push( *t );
	}
}

int main()
{
	string from, to;

	while( cin >> from >> to )
	{
		if( !is_permutation( from.begin(), from.end(), to.begin() ) )
		{
			cout << "[\n]\n";
			continue;
		}
		stack<char> word;
		cout << "[\n";
		dfs( word, from.begin(), from.end(), to.begin(), to.end() );
		cout << "]\n";
	}
}
