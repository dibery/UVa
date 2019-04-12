#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
	int t, battle, G, B, in, *outg = new int[ 100000 ], *outb = new int[ 100000 ];
	scanf( "%d", &t );

	while( t-- )
	{
		priority_queue<int>green, blue;
		int scoreg = 0, scoreb = 0;
		scanf( "%d %d %d", &battle, &G, &B );

		for( int i = 0; i < G; ++i )
			scanf( "%d", &in ), green.push( in ), scoreg += in;
		for( int i = 0; i < B; ++i )
			scanf( "%d", &in ), blue.push( in ), scoreb += in;

		while( scoreb != scoreg && !green.empty() && !blue.empty() )
		{
			memset( outg, 0, sizeof( outg ) );
			memset( outb, 0, sizeof( outb ) );
			int use = min( battle, (int)min( green.size(), blue.size() ) );

			for( int i = 0; i < use; ++i )
			{
				if( !green.empty() )
					outg[ i ] = green.top(), green.pop();
				if( !blue.empty() )
					outb[ i ] = blue.top(),	blue.pop();
				if( outb[ i ] > outg[ i ] )
					outb[ i ] -= outg[ i ], outg[ i ] = 0;
				else
					outg[ i ] -= outb[ i ], outb[ i ] = 0;
			}
			for( int i = 0; i < use; ++i )
				if( outb[ i ] )
					blue.push( outb[ i ] );
				else if( outg[ i ] )
					green.push( outg[ i ] );
		}
		if( scoreg == scoreb )
			puts( "green and blue died" );
		else if( scoreb > scoreg )
		{
			puts( "blue wins" );
			while( !blue.empty() )
				printf( "%d\n", blue.top() ), blue.pop();
		}
		else
		{
			puts( "green wins" );
			while( !green.empty() )
				printf( "%d\n", green.top() ), green.pop();
		}
		if( t )
			puts( "" );
	}

	return 0;
}
