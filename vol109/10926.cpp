#include<iostream>
#include<set>
#include<algorithm>
using namespace std;

int main()
{
	int task, s, d;

	while( cin >> task && task )
	{
		set<int> dep[ task ], path[ task ];
		unsigned int M = 0, pos;
		bool vis[ task ];
		fill( vis, vis+task, false );

		for( int i = 0; i < task; ++i )
			for( cin >> s; s; --s )
				cin >> d, dep[ i ].insert( d-1 );
		while( count( vis, vis+task, false ) )
			for( int i = 0; i < task; ++i )
				if( dep[ i ].size() == 0 && !vis[ i ] )
				{
					vis[ i ] = true;
					for( int j = 0; j < task; ++j )
						if( dep[ j ].find( i ) != dep[ j ].end() )
						{
							path[ j ].insert( path[ i ].begin(), path[ i ].end() );
							path[ j ].insert( i );
							dep[ j ].erase( i );
						}
				}
		for( int i = 0; i < task; ++i )
			if( path[ i ].size() > M )
				pos = i, M = path[ i ].size();
		cout << pos+1 << endl;
	}
}
