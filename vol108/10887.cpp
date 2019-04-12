#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, a, b;
	string s;
	cin >> t;

	for( int n = 1; n <= t; ++n )
	{
		vector<string> va, vb;
		set<string> con;

		cin >> a >> b;
		cin.get();
		for( int i = 0; i < a; ++i )
			getline( cin, s ), va.push_back( s );
		for( int i = 0; i < b; ++i )
			getline( cin, s ), vb.push_back( s );
		for( int i = 0; i < a; ++i )
			for( int j = 0; j < b; ++j )
				con.insert( va[ i ] + vb[ j ] );
		printf( "Case %d: %u\n", n, con.size() );
	}
}
