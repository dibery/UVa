#include<bits/stdc++.h>
using namespace std;

const int N = 100001;
int n, len, match[ N ], ans[ N ], t;
char s[ N ];
const char *LEFT = "<([{", *WHOLE = "<>()[]{}";

int main()
{
	for( scanf( "%d", &n ); n-- && scanf( "%s", s ); )
	{
		stack<pair<char,int>> bracket;
		memset( match, -1, sizeof( match ) );
		memset( ans, 0, sizeof( ans ) );

		for( len = 0; s[ len ]; ++len )
			if( strchr( "<([{", s[ len ] ) )
				bracket.emplace( s[ len ], len );
			else if( !bracket.empty() && *( strchr( WHOLE, s[ len ] ) - 1 ) == bracket.top().first )
			{
				match[ bracket.top().second ] = len;
				bracket.pop();
			}
			else
				while( !bracket.empty() )
					bracket.pop();

		for( --len; len >= 0; --len )
			if( match[ len ] == -1 )
				ans[ len ] = 0;
			else
				ans[ len ] = match[ len ] - len + 1 + ans[ match[ len ] + 1 ];

		printf( "Case %d:\n", ++t );
		for( len = 0; s[ len ]; ++len )
			printf( "%d\n", ans[ len ] );
	}
}
