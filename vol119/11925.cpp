#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int final[ 300 ];
	for( int i = 0; i < 300; ++i )
		final[ i ] = i + 1;

	for( int list[ 300 ], len; scanf( "%d", &len ) && len; puts( "" ) )
	{
		for( int i = 1, tmp; i <= len; ++i )
		{
			scanf( "%d", &tmp );
			list[ tmp - 1 ] = i;
		}
		while( mismatch( list, list + len, final ).first != list + len )
			if( list[ 1 ] == 1 || list[ 0 ] < list[ 1 ] )
			{
				putchar( '2' );
				int x = list[ 0 ];
				for( int i = 0; i < len - 1; ++i )
					list[ i ] = list[ i + 1 ];
				list[ len - 1 ] = x;
			}
			else
			{
				printf( "12" );
				int x = list[ 1 ];
				for( int i = 1; i < len - 1; ++i )
					list[ i ] = list[ i + 1 ];
				list[ len - 1 ] = x;
			}
	}
}
