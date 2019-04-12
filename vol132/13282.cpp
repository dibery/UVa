#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int N, M, in[ 2000 ], out[ 2000 ], *diff = new int[ 4000005 ]; ~scanf( "%d %d", &N, &M ); )
	{
		int max_t = 0, ans = 0, size = 0;

		for( int i = 0; i < N; ++i )
			scanf( "%d", in + i );
		for( int i = 0; i < M; ++i )
			scanf( "%d", out + i );

		for( int i = 0; i < N; ++i )
			for( int j = 0; j < M; ++j )
				if( out[ j ] >= in[ i ] )
					diff[ size++ ] = out[ j ] - in[ i ];
		sort( diff, diff + size );

		for( int i = 0, last = -1, count = 0; i <= size; ++i )
			if( i == size || last != diff[ i ] )
			{
				if( max_t < count )
					max_t = count, ans = last;
				last = diff[ i ];
				count = 1;
			}
			else
				++count;

		printf( "%d\n", ans );
	}
}
