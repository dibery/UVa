#include<bits/stdc++.h>

int main()
{
	int T, bulb, Switch, switches[ 40 ], q, *dist = new int[ 1 << 15 ];
	char input[ 20 ];

	scanf( "%d", &T );
	*dist = 0;

	for( int t = 1; t <= T && scanf( "%d %d", &bulb, &Switch ); ++t, puts( "" ) )
	{
		memset( switches, 0, sizeof( switches ) );
		std::fill( dist + 1, dist + ( 1 << bulb ), -1 );

		for( int i = 0, k, p; i < Switch && scanf( "%d", &k ); ++i )
			while( k-- && scanf( "%d", &p ) )
				switches[ i ] |= 1 << p;

		std::queue<int> bfs;
		for( bfs.push( 0 ); !bfs.empty(); bfs.pop() )
			for( int i = 0; i < Switch; ++i )
				if( !~dist[ bfs.front() ^ switches[ i ] ] )
				{
					dist[ bfs.front() ^ switches[ i ] ] = dist[ bfs.front() ] + 1;
					bfs.push( bfs.front() ^ switches[ i ] );
				}

		printf( "Case %d:\n", t );
		for( scanf( "%d", &q ); q-- && scanf( "%s", input ); )
			printf( "%d\n", dist[ strtol( input, NULL, 2 ) ] );
	}
}
