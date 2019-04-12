#include<bits/stdc++.h>
using namespace std;

int main()
{
	int big, small, B[ 10 ][ 10 ], S[ 10 ][ 10 ];
	char in[ 11 ];

	while( scanf( "%d %d", &big, &small ) && big )
	{
		bool match = false;
		memset( B, 0, sizeof( B ) );
		memset( S, 0, sizeof( S ) );
		for( int i = 0; i < big && scanf( "%s", in ); ++i )
			for( int j = 0; j < big; ++j )
				B[ i ][ j ] = in[ j ] == '*';
		for( int i = 0; i < small && scanf( "%s", in ); ++i )
			for( int j = 0; j < small; ++j )
				S[ i ][ j ] = in[ j ] == '*';
		if( accumulate( B[ 0 ], B[ big ], 0 ) == accumulate( S[ 0 ], S[ 10 ], 0 ) * 2 )
			for( int i = -small + 1; i < big; ++i )
				for( int j = -small + 1; j < big; ++j )
					for( int k = -small + 1; k < big; ++k )
						for( int l = -small + 1; l < big; ++l )
						{
							int test[ 10 ][ 10 ] = { { 0 } };
							for( int m = 0; m < small; ++m )
								for( int n = 0; n < small; ++n )
									if( S[ m ][ n ] && i + m >= 0 && i + m < big && j + n >= 0 && j + n < big )
										test[ i + m ][ j + n ] += S[ m ][ n ];
							for( int m = 0; m < small; ++m )
								for( int n = 0; n < small; ++n )
									if( S[ m ][ n ] && k + m >= 0 && k + m < big && l + n >= 0 && l + n < big )
										test[ k + m ][ l + n ] += S[ m ][ n ];
							match |= !memcmp( test, B, sizeof( B ) );
						}
		printf( "%d\n", match );
	}
}
