#include<bits/stdc++.h>
using namespace std;

int get_next( vector<int>& adj, int light )
{
	for( int i: adj )
		if( ~light & 1 << i )
			return i;
	return -1;
}

int main()
{
	char maze[ 256 ], monster, man;
	int step;

	while( scanf( "%s %c %c %d", maze, &monster, &man, &step ) == 4 )
	{
		vector<int> adj[ 26 ];
		monster -= 'A', man -= 'A';
		for( char *c = maze, start = *c - 'A'; *c; start = *++c - 'A' )
			for( ++c; *c != '.' && *c != ';'; ++c )
				if( isupper( *c ) )
					adj[ start ].push_back( *c - 'A' );
		for( int i = 0, light = 1 << man, next; ~( next = get_next( adj[ monster ], light ) ); )
		{
			if( i % step || !i )
				light &= ~( 1 << man );
			man = monster;
			monster = next;
			light |= 1 << man;
			if( ++i % step == 0 )
				printf( "%c ", 'A' + man );
		}
		printf( "/%c\n", monster + 'A' );
	}
}
