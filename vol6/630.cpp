#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t, size;

	for( cin >> t; t--; )
	{
		vector<string> dict;
		string in;

		for( cin >> size; size--; )
			cin >> in, dict.push_back( in );
		while( cin >> in && in != "END" )
		{
			int index = 0;
			cout << "Anagrams for: " << in << endl;
			for( int i = 0; i < dict.size(); ++i )
				if( is_permutation( dict[ i ].begin(), dict[ i ].end(), in.begin() ) )
					cout << setw(3) << ++index << ") " << dict[ i ] << endl;
			if( !index )
				cout << "No anagrams for: " << in << endl;
		}
		cout << ( t? "\n" : "" );
	}
}
