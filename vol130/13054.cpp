#include<cstdio>
#include<algorithm>

int main()
{
	int n, door, alone, carry, h[ 100000 ], t;
	
	scanf( "%d", &t );
	for( int N = 1; N <= t && scanf( "%d %d %d %d", &n, &door, &alone, &carry ) == 4; )
	{
		int time = 0;

		for( int i = 0; i < n; ++i )
			scanf( "%d", h + i );
		std::sort( h, h + n );

		for( int front = 0, back = n - 1; back >= front; )
			if( front == back )
				time += alone, --back;
			else if( h[ front ] + h[ back ] < door && alone * 2 >= carry )
				time += carry, ++front, --back;
			else
				time += alone, --back;
		printf( "Case %d: %d\n", N++, time );
	}
}
