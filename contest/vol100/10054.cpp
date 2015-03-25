#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, q, from, to;
	cin >> t;

	for( int n = 1; n <= t; ++n )
	{
		cin >> q;
		int count[ 51 ] = { 0 };
		multiset<int> lnk[ 51 ];
		set<int> show;
		stack<int> path[ 51 ];

		for( int i = 0; i < q; ++i )
		{
			cin >> from >> to;
			lnk[ from ].insert( to );
			lnk[ to ].insert( from );
			++count[ from ];
			++count[ to ];
		}

		show.insert( find_if( lnk, lnk+51, [] ( multiset<int>& s ) { return !s.empty(); } ) - lnk );
		for( int pos = *show.begin(); pos != -1; )
		{
			vector<int> tmp[ 51 ];
			while( !lnk[ pos ].empty() )
			{
				int next = *lnk[ pos ].begin();
				show.insert( next );
				tmp[ pos ].push_back( next );
				lnk[ next ].erase( lnk[ next ].find( pos ) );
				lnk[ pos ].erase( lnk[ pos ].find( next ) );
				pos = next;
			}
			for( int i = 1; i <= 50; ++i )
				for( int j = tmp[ i ].size() - 1; j >= 0; --j )
					path[ i ].push( tmp[ i ][ j ] );
			set<int>::iterator it = find_if( show.begin(), show.end(), [ lnk ] ( int i ) { return !lnk[ i ].empty(); } );
			pos = it == show.end()? -1 : *it;
		}

		printf( "Case #%d\n", n );
		if( any_of( count, count+51, [] ( int i ) { return i & 1; } ) ||
				any_of( lnk, lnk+51, [] ( multiset<int>& s ) { return !s.empty(); } ) )
			puts( "some beads may be lost" );
		else
			for( int pos = *show.begin(), tmp; !path[ pos ].empty(); pos = path[ pos ].top(), path[ tmp ].pop() )
				printf( "%d %d\n", tmp = pos, path[ pos ].top() );
		if( n < t )
			puts( "" );
	}
}
