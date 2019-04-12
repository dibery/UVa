#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int times; cin >> times; )
	{
		map<string,int> stat;

		for( string s; cin >> s && s != "EndOfText"; ++stat[ regex_replace( s, regex( "[^a-z]" ), "" ) ] )
			transform( s.begin(), s.end(), s.begin(), ::tolower );

		for( auto i: stat )
			if( i.second == times )
				cout << i.first << endl;
	}
}
