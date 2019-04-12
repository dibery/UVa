#include<cstdio>
#include<vector>

int main()
{
	bool first = true;

	for( int cap, scale, item; scanf( "%d %d %d", &cap, &scale, &item ) == 3; )
	{
		int ks[ 1001 ][ 30 ] = { { 0 } }, w[ 30 ], v[ 30 ];
		std::vector<int> content[ 1001 ][ 30 ];

		for( int i = 0; i < item; w[ i++ ] *= scale * 3 )
			scanf( "%d %d", w + i, v + i );

		for( int i = w[ 0 ]; i <= cap; ++i )
		{
			ks[ i ][ 0 ] = v[ 0 ];
			content[ i ][ 0 ].push_back( 0 );
		}
		for( int W = 1; W <= cap; ++W )
			for( int i = 1; i < item; ++i )
				if( W >= w[ i ] )
					if( ks[ W ][ i - 1 ] > ks[ W - w[ i ] ][ i - 1 ] + v[ i ] )
					{
						ks[ W ][ i ] = ks[ W ][ i - 1 ];
						content[ W ][ i ] = content[ W ][ i - 1 ];
					}
					else
					{
						ks[ W ][ i ] = v[ i ] + ks[ W - w[ i ] ][ i - 1 ];
						content[ W ][ i ] = content[ W - w[ i ] ][ i - 1 ];
						content[ W ][ i ].push_back( i );
					}
				else
				{
					ks[ W ][ i ] = ks[ W ][ i - 1 ];
					content[ W ][ i ] = content[ W ][ i - 1 ];
				}

		if( first )
			first = false;
		else
			puts( "" );

		--item;
		printf( "%d\n%lu\n", ks[ cap ][ item ], content[ cap ][ item ].size() );
		for( int i: content[ cap ][ item ] )
			printf( "%d %d\n", w[ i ] / scale / 3, v[ i ] );
	}
}
