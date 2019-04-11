#include<cstdio>
#include<algorithm>
#define M 1e6
using namespace std;

int main()
{
	for( int edge, w, me, he; scanf( "%d%*c", &edge ) && edge; puts( "" ) )
	{
		int young[ 26 ][ 26 ], old[ 26 ][ 26 ], B[ 26 ], m = M;
		char type, b, e, dir;

		fill( *young, young[ 26 ], M );
		fill( *old, old[ 26 ], M );

		for( int i = 0; i < edge && scanf( "%c %c %c %c %d%*c", &type, &dir, &b, &e, &w ); ++i )
			if( type == 'Y' )
				if( dir == 'U' )
					young[ b - 'A' ][ e - 'A' ] = w;
				else
					young[ b - 'A' ][ e - 'A' ] = young[ e - 'A' ][ b - 'A' ] = w;
			else
				if( dir == 'U' )
					old[ b - 'A' ][ e - 'A' ] = w;
				else
					old[ b - 'A' ][ e - 'A' ] = old[ e - 'A' ][ b - 'A' ] = w;
		for( int i = 0; i < 26; ++i )
			young[ i ][ i ] = old[ i ][ i ] = 0;

		scanf( "%c %c%*c", &b, &e );
		me = b - 'A';
		he = e - 'A';

		for( int m = 0; m < 26; ++m )
			for( int b = 0; b < 26; ++b )
				for( int e = 0; e < 26; ++e )
				{
					young[ b ][ e ] = min( young[ b ][ e ], young[ b ][ m ] + young[ m ][ e ] );
					old[ b ][ e ] = min( old[ b ][ e ], old[ b ][ m ] + old[ m ][ e ] );
				}
		for( int i = 0; i < 26; ++i )
			m = min( m, B[ i ] = young[ me ][ i ] + old[ he ][ i ] );

		if( m == M )
			printf( "You will never meet." );
		else
		{
			printf( "%d", m );
			for( int i = 0; i < 26; ++i )
				if( B[ i ] == m )
					printf( " %c", 'A' + i );
		}
	}
}
