#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int vertex, edge, year;
	char wake[ 30 ], n[ 3 ];

	while( scanf( "%d %d %s", &vertex, &edge, wake ) == 3 )
	{
		bool adj[ 26 ][ 26 ] = { false }, awake[ 26 ] = { false };

		for( int i = 0; i < edge; ++i )
			scanf( "%s", n ), adj[ n[0]-'A' ][ n[1]-'A' ] = adj[ n[1]-'A' ][ n[0]-'A' ] = true;
		for( int i = 0; wake[ i ]; ++i )
			awake[ wake[ i ]-'A' ] = true;
		for( year = 0; count( awake, awake+26, true ) < vertex && year < 26; ++year )
		{
			bool tmp[ 26 ] = { false };
			for( int i = 0; i < 26; ++i )
				if( !awake[ i ] )
				{
					int cnt = 0;
					for( int j = 0; j < 26 && cnt < 4; ++j )
						if( adj[ i ][ j ] && awake[ j ] )
							++cnt;
					if( cnt >= 3 )
						tmp[ i ] = true;
				}
			for( int i = 0; i < 26; ++i )
				awake[ i ] |= tmp[ i ];
		}
		if( year < 26 )
			printf( "WAKE UP IN, %d, YEARS\n", year );
		else
			puts( "THIS BRAIN NEVER WAKES UP" );
	}
}
