#include<cstdio>
#include<climits>
#include<algorithm>
void path( int mid[ 10 ][ 10 ], int start, int end )
{
	if( start == end )
		printf( "A%d", start+1 );
	else
	{
		putchar( '(' );
		path( mid, start, mid[ start ][ end ] );
		printf( " x " );
		path( mid, mid[ start ][ end ] + 1, end );
		putchar( ')' );
	}
}

int main()
{
	int size, len[ 11 ] = { 0 }, t = 0;

	while( scanf( "%d", &size ) && size )
	{
		int opt[ 10 ][ 10 ] = { 0 }, split[ 10 ][ 10 ] = { 0 };
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				opt[ i ][ j ] = i == j? 0 : INT_MAX;
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", len+i, len+i+1 );
		for( int interval = 1; interval < size; ++interval )
			for( int start = 0; start + interval < size; ++start )
				for( int mid = start; mid < start + interval; ++mid )
				{
					int mul = opt[ start ][ mid ] + opt[ mid+1 ][ start+interval ] + len[ start ] * len[ mid+1 ] * len[ start+interval+1 ];
					if( mul < opt[ start ][ start + interval ] )
					{
						opt[ start ][ start + interval ] = mul;
						split[ start ][ start + interval ] = mid;
					}
				}
		printf( "Case %d: ", ++t );
		path( split, 0, size-1 );
		puts( "" );
	}
	return 0;
}
