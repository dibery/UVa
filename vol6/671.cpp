#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string>
using namespace std;

bool ok( string a, string b )
{
	if( max( a.size(), b.size() ) - min( a.size(), b.size() ) > 1 )
		return false;
	if( a.size() == b.size() )
	{
		pair<string::iterator,string::iterator> d = mismatch( a.begin(), a.end(), b.begin() );
		return mismatch( next( d.first ), a.end(), next( d.second ) ).first == a.end();
	}
	if( a.size() > b.size() )
		swap( a, b );	// a is shorter
	pair<string::iterator,string::iterator> d = mismatch( a.begin(), a.end(), b.begin() );
	return mismatch( d.first, a.end(), next( d.second ) ).first == a.end();
}

int main()
{
	int t;
	string in;

	for( cin >> t; t--; )
	{
		vector<string> dict;

		while( cin >> in && in != "#" )
			dict.push_back( in );
		while( cin >> in && in != "#" )
		{
			if( find( dict.begin(), dict.end(), in ) == dict.end() )
			{
				cout << in << ':';
				for( size_t i = 0; i < dict.size(); ++i )
					if( ok( in, dict[ i ] ) )
						cout << ' ' << dict[ i ];
				cout << endl;
			}
			else
				cout << in << " is correct\n";
		}
		if( t )
			cout << endl;
	}
}
