#include<cstdio>
#include<algorithm>

int main()
{
	int size, dest, query, begin, end, t = 0;

	while( scanf( "%d", &size ) == 1 )
	{
		int aps[ 20 ][ 20 ] = { { 0 } };

		for( int i = 0; i < size; ++i )
			scanf( "%d", &dest ), aps[ 0 ][ dest-1 ] = aps[ dest-1 ][ 0 ] = 1;
		for( int i = 1; i < 19; ++i )
			for( scanf( "%d", &size ); size--; )
				scanf( "%d", &dest ), aps[ i ][ dest-1 ] = aps[ dest-1 ][ i ] = 1;

		for( int m = 0; m < 20; ++m )
			for( int b = 0; b < 20; ++b )
				for( int e = 0; e < 20; ++e )
					if( aps[ b ][ m ] && aps[ m ][ e ] )
						if( aps[ b ][ e ] )
							aps[ b ][ e ] = std::min( aps[ b ][ e ], aps[ b ][ m ] + aps[ m ][ e ] );
						else
							aps[ b ][ e ] = aps[ b ][ m ] + aps[ m ][ e ];

		printf( "Test Set #%d\n", ++t );
		scanf( "%d", &query );
		while( query-- )
		{
			scanf( "%d %d", &begin, &end );
			printf( "%2d to %2d: %d\n", begin, end, aps[ begin-1 ][ end-1 ] );
		}
		puts( "" );
	}
}
