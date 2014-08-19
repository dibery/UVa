#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
using namespace std;
int perm[ 100000 ][ 3 ] = { { 0 } };

int main()
{
	int score, dart[ 60 ], size = 0, shot[ 3 ];
	bool reach[ 61 ] = { true };

	for( int i = 1; i <= 20; ++i )
		reach[ i ] = reach[ i*2 ] = reach[ i*3 ] = true;
	reach[ 50 ] = true;
	for( int i = 0; i <= 60; ++i )
		if( reach[ i ] )
			dart[ size++ ] = i;

	while( scanf( "%d", &score ) && score > 0 )
	{
		memset( perm, 0, sizeof( perm ) );
		int way = 0;
		set<int> all;

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				for( int k = 0; k < size; ++k )
					if( dart[ i ] + dart[ j ] + dart[ k ] == score )
					{
						++way;
						shot[ 0 ] = dart[ i ];
						shot[ 1 ] = dart[ j ];
						shot[ 2 ] = dart[ k ];
						sort( shot, shot+3 );
						int now = shot[ 0 ] * 10000 + shot[ 1 ] * 100 + shot[ 2 ];
						if( all.find( now ) == all.end() )
							all.insert( now );
					}
		if( !all.empty() )
		{
			printf( "NUMBER OF COMBINATIONS THAT SCORES %d IS %u.\n", score, all.size() );
			printf( "NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", score, way );
		}
		else
			printf( "THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", score );
		puts( "**********************************************************************" );
	}
	puts( "END OF OUTPUT" );
}
