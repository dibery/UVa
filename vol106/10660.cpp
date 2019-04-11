#include<bits/stdc++.h>
#define a pos[ 0 ]
#define b pos[ 1 ]
#define c pos[ 2 ]
#define d pos[ 3 ]
#define e pos[ 4 ]
using namespace std;

int main()
{
	int t, p;

	for( cin >> t; t--; )
	{
		int live[ 5 ][ 5 ] = { { 0 } }, cost = INT_MAX, pos[ 5 ], ans[ 5 ];

		cin >> p;
		for( int x, y; p--; cin >> live[ x ][ y ] )
			cin >> x >> y;

		for( a = 0; a < 25; ++a )
			for( b = a + 1; b < 25; ++b )
				for( c = b + 1; c < 25; ++c )
					for( d = c + 1; d < 25; ++d )
						for( e = d + 1; e < 25; ++e )
						{
							int now = 0;
							for( int i = 0; i < 5; ++i )
								for( int j = 0; j < 5; ++j )
								{
									int This = INT_MAX;
									for( int k = 0; k < 5; ++k )
										This = min( This, abs( pos[ k ] / 5 - i ) + abs( pos[ k ] % 5 - j ) );
									now += This * live[ i ][ j ];
								}
							if( now < cost )
								cost = now, copy( pos, pos + 5, ans );
						}
		for( int i = 0; i < 5; ++i )
			printf( "%d%c", ans[ i ], i < 4? ' ' : '\n' );
	}
}
