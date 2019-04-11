#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, v, e, map[ 26 ] = { 0 };
	char all[ 50 ] = { 0 };
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		bool adj[ 15 ][ 15 ] = { { false } };
		string dp[ 32768 ][ 15 ];

		scanf( "%d %d\n", &v, &e );
		char src = *gets( all ), target = all[ strlen( all ) - 1 ];

		sort( all, all + strlen( all ), std::greater<char>() );
		*strchr( all, ' ' ) = 0;
		reverse( all, all + v );
		for( int i = 0; i < v; ++i )
			map[ all[ i ] - 'A' ] = i;

		for( char from, to; e--; adj[ map[ from - 'A' ] ][ map[ to - 'A' ] ] = adj[ map[ to - 'A' ] ][ map[ from - 'A' ] ] = true )
			scanf( "%c %c%*c", &from, &to );

		dp[ 1 << map[ target - 'A' ] ][ map[ target - 'A' ] ] = string( 1, target );

		for( int one = 2; one <= v; ++one )
		{
			char state[ 16 ] = { 0 };
			fill_n( state, v-one, '0' );
			fill_n( state+v-one, one, '1' );

			do
			{
				int now = strtol( state, NULL, 2 );
				for( int begin = 0; begin < v; ++begin )
					if( now & 1 << begin )
						for( int next = 0; next < v && dp[ now ][ begin ].empty(); ++next )
							if( now & 1 << next && adj[ begin ][ next ] && !dp[ now ^ 1 << begin ][ next ].empty() )
								dp[ now ][ begin ] = string( 1, all[ begin ] ) + dp[ now ^ 1 << begin ][ next ];
			} while( next_permutation( state, state+v ) );
		}

		string& ans = dp[ ( 1 << v ) - 1 ][ map[ src - 'A' ] ];
		printf( "Case %d: %s\n", n, ans.empty()? "impossible" : ans.c_str() );
	}
}
