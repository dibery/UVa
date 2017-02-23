#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int animal, relation; cin >> animal >> relation && animal; )
	{
		string name[ animal ];
		map<string,int> lookup;
		map<int,set<string>> groups;
		int idx = 0, ans = 1;

		for( int i = 0; i < animal; ++i )
			cin >> name[ i ];
		for( string a, b; relation-- && cin >> a >> b; )
			if( lookup.find( a ) == lookup.end() && lookup.find( b ) == lookup.end() )
			{
				groups[ idx ].insert( a );
				groups[ idx ].insert( b );
				lookup[ a ] = lookup[ b ] = idx++;
			}
			else if( lookup.find( a ) != lookup.end() && lookup.find( b ) == lookup.end() )
			{
				groups[ lookup[ a ] ].insert( b );
				lookup[ b ] = lookup[ a ];
			}
			else if( lookup.find( a ) == lookup.end() && lookup.find( b ) != lookup.end() )
			{
				groups[ lookup[ b ] ].insert( a );
				lookup[ a ] = lookup[ b ];
			}
			else if( groups[ lookup[ a ] ].size() < groups[ lookup[ b ] ].size() )
			{
				int A = lookup[ a ], B = lookup[ b ];
				auto& g = groups[ B ];
				for( auto& i: groups[ A ] )
				{
					g.insert( i );
					lookup[ i ] = B;
				}
				groups.erase( A );
			}
			else if( lookup[ a ] != lookup[ b ] )
			{
				int A = lookup[ a ], B = lookup[ b ];
				auto& g = groups[ A ];
				for( auto& i: groups[ B ] )
				{
					g.insert( i );
					lookup[ i ] = A;
				}
				groups.erase( B );
			}

		for( auto& i: groups )
			ans = max( ans, int( i.second.size() ) );
		cout << ans << endl;
	}
}
