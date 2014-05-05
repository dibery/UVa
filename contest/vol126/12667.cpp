#include<cstdio>
class ques
{
	public:
		int solve, time;
		ques() { time = solve = -1; }
		void update( int at, int team ) { time = at; solve = team; }
} set[ 12 ];

int main()
{
	int prob, sub, team, time;
	char result[ 4 ], id;
	bool AC[ 12 ][ 101 ] = { false };
	scanf( "%d %d %d", &prob, &team, &sub );
	
	for( int i = 0; i < sub; ++i )
	{
		scanf( "%d %d %c %s", &time, &team, &id, result );
		if( *result == 'Y' && !AC[ id - 'A' ][ team ] )
			set[ id - 'A' ].update( time, team ), AC[ id - 'A' ][ team ] = true;
	}
	for( int i = 0; i < prob; ++i )
		if( set[ i ].solve != -1 )
			printf( "%c %d %d\n", 'A'+i, set[ i ].time, set[ i ].solve );
		else
			printf( "%c - -\n", 'A'+i );

	return 0;
}
