#include<bits/stdc++.h>
#define end begin + len
using namespace std;

int main()
{
	for( int size, num[ 100 ]; scanf( "%d", &size ) && size; )
	{
		int ans[ 101 ][ 101 ] = { { 0 } }, sum[ 101 ][ 101 ] = { { 0 } };

		for( int i = 0; i < size; ++i )
			scanf( "%d", num + i );
		for( int i = 0; i < size; ++i )
			for( int j = i + 1; j <= size; ++j )
				sum[ i ][ j ] = accumulate( num + i, num + j, 0 );
		for( int len = 1; len <= size; ++len )
			for( int begin = 0; end <= size; ++begin )
			{
				ans[ begin ][ end ] = sum[ begin ][ end ];
				for( int i = begin + 1; i < end; ++i )
					ans[ begin ][ end ] = max( ans[ begin ][ end ], sum[ begin ][ i ] - ans[ i ][ end ] );
				for( int i = begin; i < end; ++i )
					ans[ begin ][ end ] = max( ans[ begin ][ end ], sum[ i ][ end ] - ans[ begin ][ i ] );
			}
		printf( "%d\n", ans[ 0 ][ size ] );
	}
}
