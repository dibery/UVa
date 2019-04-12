#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int node, query, x[ 3000 ], y[ 3000 ], r; cin >> node >> query && node; puts( "" ) )
	{
		vector<pair<int,int>> dist[ 3000 ];

		for( int i = 0; i < node; ++i )
			scanf( "%d %d", x + i, y + i );

		for( int i = 0; i < node; ++i )
		{
			for( int j = 0; j < node; ++j )
				dist[ i ].push_back( make_pair( ( x[ i ] - x[ j ] ) * ( x[ i ] - x[ j ] ) + ( y[ i ] - y[ j ] ) * ( y[ i ] - y[ j ] ), j ) );
			sort( dist[ i ].begin(), dist[ i ].end() );
		}

		while( query-- && scanf( "%d", &r ) )
		{
			double E = 0;
			for( int i = 0; i < node; ++i )
				E += distance( dist[ i ].begin(), upper_bound( dist[ i ].begin(), dist[ i ].end(), make_pair( r * r, node ) ) );
			printf( "%.2f\n", E / node );
		}
	}
}
