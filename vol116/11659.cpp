#include<bits/stdc++.h>
using namespace std;

int main()
{
	int man, state, say, target;

	while( scanf( "%d %d", &man, &state ) && man )
	{
		bool rely[ 20 ];
		fill( rely, rely+man, true );

		for( int i = 0; i < state; ++i )
		{
			scanf( "%d %d", &say, &target );
			if( target < 0 )
				rely[ -target-1 ] = false;
		}

		printf( "%d\n", count( rely, rely+man, true ) );
	}
}
