#include<bits/stdc++.h>
using namespace std;

int main()
{
	set<string> dict;

	for( string s; cin >> s; dict.insert( s ) );

	for( auto s: dict )
		for( int i = 1; i < s.size(); ++i )
			if( dict.find( s.substr( 0, i ) ) != dict.end() && dict.find( s.substr( i, s.size() - i ) ) != dict.end() )
				cout << s << endl, i = s.size();
}
