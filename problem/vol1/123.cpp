#include<cctype>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<sstream>
#include<utility>
using namespace std;

class title
{
	public:
		title( int k, string s )
		{
			key = k;
			stringstream ss( s );
			string tmp;
			for( int i = 0; ss >> tmp; ++i )
			{
				if( i == k )
					transform( tmp.begin(), tmp.end(), tmp.begin(), ::toupper ), str += ( tmp + " " );
				else
					transform( tmp.begin(), tmp.end(), tmp.begin(), ::tolower ), str += ( tmp + " " );
				seq.push_back( tmp );
			}
			str.pop_back();
		}
		bool operator< ( const title& rhs ) const { return seq[ key ] < rhs.seq[ rhs.key ]; }
		int key;
		string str;
		vector<string> seq;
		static vector<string> keyword;
};
vector<string> title::keyword;

int main()
{
	string s, seg;
	vector<title> all;

	while( getline( cin, s ) && s != "::" )
		title::keyword.push_back( s );
	while( getline( cin, s ) )
	{
		stringstream ss( s );
		for( int index = 0; ss >> seg; ++index )
		{
			transform( seg.begin(), seg.end(), seg.begin(), ::tolower );
			if( find( title::keyword.begin(), title::keyword.end(), seg ) == title::keyword.end() )
				all.push_back( title( index, s ) );
		}
	}
	stable_sort( all.begin(), all.end() );
	for( vector<title>::iterator i = all.begin(); i != all.end(); ++i )
		cout << i->str << endl;
}
