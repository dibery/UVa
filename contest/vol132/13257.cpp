#include<bits/stdc++.h>
using namespace std;

int main()
{
	scanf( "%*d\n" );
	for( char s[ 100001 ]; gets( s ); )
	{
		vector<int> pos[ 26 ];
		int ans = 0;

		for( int i = 0; s[ i ]; ++i )
			pos[ s[ i ] - 'A' ].push_back( i );

		for( int i = 0; i < 26; ++i )
			if( !pos[ i ].empty() )
				for( int j = 0; j < 26; ++j )
				{
					auto pj = lower_bound( pos[ j ].begin(), pos[ j ].end(), pos[ i ][ 0 ] + 1 );
					if( pj != pos[ j ].end() )
						for( int k = 0; k < 26; ++k )
							ans += !pos[ k ].empty() && pos[ k ].back() > *pj;
				}
		printf( "%d\n", ans );
	}
}
