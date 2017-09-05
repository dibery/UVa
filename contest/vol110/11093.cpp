#include<cstdio>
#include<numeric>

int main()
{
	int c, station, gas[ 100000 ], start, test;

	scanf( "%d", &c );
	for( int t = 1; t <= c; ++t )
	{
		scanf( "%d", &station );
		for( int i = 0; i < station; ++i )
			scanf( "%d", gas + i );
		for( int i = 0, minus; i < station; ++i )
			scanf( "%d", &minus ), gas[ i ] -= minus;
		if( std::accumulate( gas, gas + station, 0 ) < 0 )
			printf( "Case %d: Not possible\n", t );
		else
		{
			bool found = false;
			for( test = start = 0; !found; start = found? start : ++test )
				for( int s = 0; s + gas[ test % station ] >= 0 && !found; found |= ++test == start + station )
					s += gas[ test % station ];
			printf( "Case %d: Possible from station %d\n", t, start + 1 );
		}
	}
}
