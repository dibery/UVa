#include<iostream>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<string,int> seg;

int main()
{
	int t, cut, pos[ 1000 ];
	string str;

	for( cin >> t; t--; )
	{
		vector<seg> stat;
		int total = 0, idx = 0;

		cin >> cut;
		for( int i = 0; i < cut; ++i )
			cin >> pos[ i ];
		cin >> str;

		stat.push_back( seg( str, 0 ) );
		for( int i = 0; i < cut; ++i )
		{
			for( idx = 0; idx < stat.size(); ++idx )
				if( stat[ idx ].second <= pos[ i ] && stat[ idx ].second + stat[ idx ].first.size() > pos[ i ] )
					break;
			seg s = stat[ idx ];
			string sa = s.first.substr( 0, pos[ i ] - s.second ), sb = s.first.substr( pos[ i ] - s.second );

			for( char c = 'a'; c <= 'z'; ++c )
				total += sa.find( c ) == sa.npos ^ sb.find( c ) == sb.npos;
			stat.push_back( seg( sa, s.second ) );
			stat.push_back( seg( sb, s.second + sa.size() ) );
			stat.erase( stat.begin() + idx );
		}

		cout << total << endl;
	}
}
