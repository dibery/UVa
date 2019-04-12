#include<bits/stdc++.h>
using namespace std;
const int N = 100;

void dfs( int at, bool vis[], bool adj[ N ][ N ], int city, int skip = -1 )
{
	vis[ at ] = true;
	for( int i = 0; i < city; ++i )
		if( adj[ at ][ i ] && !vis[ i ] && i != skip )
			dfs( i, vis, adj, city, skip );
}

int main()
{
	int t = 0, city, route;
	bool first = true;
	string name[ N ], from, to;

	while( cin >> city && city )
	{
		map<string,int> lookup;
		bool adj[ N ][ N ] = { { false } }, proc[ N ] = { false };
		set<string> camera;

		if( first )
			first = false;
		else
			cout << endl;

		for( int i = 0; i < city && cin >> name[ i ]; ++i )
			lookup[ name[ i ] ] = i;
		for( cin >> route; route-- && cin >> from >> to; )
			adj[ lookup[ from ] ][ lookup[ to ] ] = adj[ lookup[ to ] ][ lookup[ from ] ] = 1;

		for( int i = 0; i < city; ++i )
			if( !proc[ i ] )
			{
				bool current[ N ] = { false };
				int test = -1;

				dfs( i, current, adj, city );

				for( int j = 0; j < city; ++j )
					if( j != i && current[ j ] )
					{
						bool cmp[ N ] = { false };
	
						if( adj[ i ][ j ] )
							test = j;
						dfs( i, cmp, adj, city, j );
						cmp[ j ] = true;
						if( memcmp( current, cmp, sizeof( current ) ) )
							camera.insert( name[ j ] );
					}
				if( test != -1 )
				{
					bool cmp[ N ] = { false };

					dfs( test, cmp, adj, city, i );
					cmp[ i ] = true;
					if( memcmp( current, cmp, sizeof( current ) ) )
						camera.insert( name[ i ] );
				}
				for( int j = 0; j < city; ++j )
					proc[ j ] |= current[ j ];
			}

		cout << "City map #" << ++t << ": " << camera.size() << " camera(s) found" << endl;
		for( auto& s: camera )
			cout << s << endl;
	}
}
