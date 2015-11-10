#include<set>
#include<map>
#include<queue>
#include<iostream>
using namespace std;

int main()
{
	for( int v, e, t = 0; cin >> v; cout << ".\n\n" )
	{
		set<int> more[ 100 ], less[ 100 ];
		bool vis[ 100 ] = { false };
		map<string,int> id;
		string lookup[ 100 ];
		int out = 0;

		for( string s; id.size() < v; lookup[ id[ s ] = id.size() - 1 ] = s )
			cin >> s;
		cin >> e;
		for( string a, b; e-- && cin >> a >> b; )
			less[ id[ a ] ].insert( id[ b ] ), more[ id[ b ] ].insert( id[ a ] );

		cout << "Case #" << ++t << ": Dilbert should drink beverages in this order:";
		while( out < v )
			for( int i = 0; i < v; ++i )
				if( !vis[ i ] && more[ i ].empty() )
				{
					cout << ' ' << lookup[ i ];
					++out;
					vis[ i ] = true;
					for( auto& j: less[ i ] )
						more[ j ].erase( i );
					break;
				}
	}
}
