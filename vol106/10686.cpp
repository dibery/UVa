#include<cctype>
#include<iostream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
using namespace std;
typedef pair< string, set<string> > group;

int main()
{
	int t, size, qnt, limit;
	string title, name, text;

	for( cin >> t; t--; )
	{
		vector<group> type;
		map< string, set<string> > exist;
		map<string,int> threshold;

		for( cin >> size; size--; )
		{
			set<string> tmp;
			cin >> title >> qnt >> limit;
			threshold[ title ] = limit;
			for( int i = 0; i < qnt; ++i )
			{
				cin >> name;
				tmp.insert( name );
			}
			type.push_back( group( title, tmp ) );
		}

		for( cin.get(); getline( cin, text ) && text != ""; )
		{
			for( int i = 0; i < text.size(); ++i )
				if( !isalpha( text[ i ] ) )
					text[ i ] = ' ';
			stringstream ss( text );
			while( ss >> name )
				for( vector<group>::iterator i = type.begin(); i != type.end(); ++i )
					if( i->second.find( name ) != i->second.end() && exist[ i->first ].find( name ) == exist[ i->first ].end() )
						--threshold[ i->first ], exist[ i->first ].insert( name );
		}

		bool out = false;
		for( int i = 0; i < type.size(); ++i )
			if( threshold[ type[ i ].first ] <= 0 )
				cout << ( out? "," : "" ) << type[ i ].first, out = true;
		if( !out )
			cout << "SQF Problem.";
		cout << endl;
	}
}
