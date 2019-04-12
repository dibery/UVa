#include<cstdio>
#include<algorithm>

int main()
{
	int device, op, load, target, amper[ 20 ], t = 0;

	while( scanf( "%d %d %d", &device, &op, &load ) && device + op + load )
	{
		int now = 0, M = 0;
		bool on[ 20 ] = { false };

		for( int i = 0; i < device; ++i )
			scanf( "%d", amper+i );
		for( int i = 0; i < op; ++i )
		{
			scanf( "%d", &target );
			--target;
			if( on[ target ] )
				now -= amper[ target ];
			else
				M = std::max( M, now += amper[ target ] );
			on[ target ] = !on[ target ];
		}

		printf( "Sequence %d\n", ++t );
		if( M > load )
			puts( "Fuse was blown.\n" );
		else
			printf( "Fuse was not blown.\nMaximal power consumption was %d amperes.\n\n", M );
	}
}
