#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<string> dict;
	string in;

	while( cin >> in && in != "XXXXXX" )
		dict.push_back( in );
	sort( dict.begin(), dict.end() );
	while( cin >> in && in != "XXXXXX" )
	{
		bool out = false;
		for( int i = 0; i < dict.size(); ++i )
			if( is_permutation( dict[ i ].begin(), dict[ i ].end(), in.begin() ) )
				cout << dict[ i ] << endl, out = true;
		if( !out )
			cout << "NOT A VALID WORD\n";
		cout << "******\n";
	}
}
