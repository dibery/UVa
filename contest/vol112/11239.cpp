#include<iostream>
#include<map>
#include<set>
#include<vector>
#include<cctype>
#include<algorithm>
using namespace std;
typedef pair< string, set<string> > PAIR;

int main()
{
	string title, name;

	while( getline( cin, title ) && title != "0" )
	{
		vector<PAIR> proj;
		map<string,int> times;

		do
		{
			proj.push_back( PAIR( title, set<string>() ) );
			while( islower( cin.peek() ) )
			{
				getline( cin, name );
				if( find( proj.back().second.begin(), proj.back().second.end(), name ) == proj.back().second.end() )
					++times[ name ];
				proj.back().second.insert( name );
			}
		}
		while( getline( cin, title ) && title != "1" );

		for( map<string,int>::iterator i = times.begin(); i != times.end(); ++i )
			if( i->second > 1 )
				for( vector<PAIR>::iterator j = proj.begin(); j != proj.end(); ++j )
					j->second.erase( i->first );

		sort( proj.begin(), proj.end(), [] ( const PAIR& a, const PAIR& b ) -> bool { return a.second.size() == b.second.size()? a.first < b.first : a.second.size() > b.second.size(); } );

		for( vector<PAIR>::iterator i = proj.begin(); i != proj.end(); ++i )
			cout << i->first << ' ' << i->second.size() << endl;
	}
}
