#include<cstdio>
#include<cstdlib>

int main()
{
	int t, know, deck[ 52 ], tmp[ 52 ], shuffle[ 100 ][ 52 ];
	char in[ 5 ], *suit[ 4 ] = { "Clubs", "Diamonds", "Hearts", "Spades" }, *face[ 13 ] = { "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace" };

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &know );
		for( int i = 0; i < know; ++i )
			for( int j = 0; j < 52; ++j )
				scanf( "%d ", shuffle[ i ]+j );
		for( int i = 0; i < 52; ++i )
			deck[ i ] = i;
		while( gets( in ) && *in )
		{
			int s = atoi( in ) - 1;
			for( int i = 0; i < 52; ++i )
				tmp[ i ] = deck[ shuffle[ s ][ i ] - 1 ];
			for( int i = 0; i < 52; ++i )
				deck[ i ] = tmp[ i ];
		}
		for( int i = 0; i < 52; ++i )
			printf( "%s of %s\n", face[ deck[ i ] % 13 ], suit[ deck[ i ] / 13 ] );
		if( t )
			puts( "" );
	}
}
