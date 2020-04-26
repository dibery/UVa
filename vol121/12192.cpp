#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int h, w, q, l, u; scanf( "%d %d", &h, &w ) && h; puts( "-" ) )
	{
		vector<int> diag[ 999 ];

		for( int i = 0; i < h; ++i )
			for( int j = 0, n; j < w && scanf( "%d", &n ); ++j )
				diag[ j - i + h - 1 ].push_back( n );

		for( scanf( "%d", &q ); q-- && scanf( "%d %d", &l, &u ); )
		{
			int ans = 0;
			for( int i = 0; i < h + w; ++i )
				ans = max( ans, int( upper_bound( diag[ i ].begin(), diag[ i ].end(), u ) - lower_bound( diag[ i ].begin(), diag[ i ].end(), l ) ) );
			printf( "%d\n", ans );
		}
	}
}
