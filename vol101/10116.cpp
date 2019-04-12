#include<cstdio>

inline bool ok( int a, int b ) { return a && a <= b; }

int main()
{
	for( int r, c, enter; scanf( "%d %d %d", &r, &c, &enter ) && r; )
	{
		char brd[ 20 ][ 20 ];
		int step = 0, vis[ 20 ][ 20 ] = { { 0 } }, R = 1, C = enter, stop = 0;
		bool found = false;

		for( int i = 1; i <= r; ++i )
			scanf( "%s", brd[ i ] + 1 );

		vis[ R ][ C ] = ++step;
		for( R = 1, C = enter; ok( R, r ) && ok( C, c ) && !found; )
			if( brd[ R ][ C ] == 'N' )
				if( vis[ --R ][ C ] )
					stop = vis[ R ][ C ], found = true;
				else
					vis[ R ][ C ] = ++step;
			else if( brd[ R ][ C ] == 'S' )
				if( vis[ ++R ][ C ] )
					stop = vis[ R ][ C ], found = true;
				else
					vis[ R ][ C ] = ++step;
			else if( brd[ R ][ C ] == 'E' )
				if( vis[ R ][ ++C ] )
					stop = vis[ R ][ C ], found = true;
				else
					vis[ R ][ C ] = ++step;
			else
				if( vis[ R ][ --C ] )
					stop = vis[ R ][ C ], found = true;
				else
					vis[ R ][ C ] = ++step;

		--stop, --step;
		if( found )
			printf( "%d step(s) before a loop of %d step(s)\n", stop, step - stop + 1 );
		else
			printf( "%d step(s) to exit\n", step );
	}
}
