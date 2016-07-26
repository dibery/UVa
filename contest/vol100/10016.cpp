#include<cstdio>
#include<algorithm>
using namespace std;

bool ok( int x, int y, int dim, int circle )
{
	return min( min( x, y ), min( dim - x - 1, dim - y - 1 ) ) == circle;
}

int main()
{
	int t, dim, brd[ 500 ][ 500 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d", &dim ); )
	{
		for( int i = 0; i < dim; ++i )
			for( int j = 0; j < dim; ++j )
				scanf( "%d", brd[ i ] + j );
		for( int i = 0, act, type; i < ( dim + 1 ) / 2 && scanf( "%d", &act ); ++i )
			for( int j = 0; j < act && scanf( "%d", &type ); ++j )
				switch( type )
				{
					case 1:
						for( int x = 0; x < dim / 2; ++x )
							for( int y = 0; y < dim; ++y )
								if( ok( x, y, dim, i ) )
									swap( brd[ x ][ y ], brd[ dim - x - 1 ][ y ] );
						break;
					case 2:
						for( int x = 0; x < dim; ++x )
							for( int y = 0; y < dim / 2; ++y )
								if( ok( x, y, dim, i ) )
									swap( brd[ x ][ y ], brd[ x ][ dim - y - 1 ] );
						break;
					case 3:
						for( int x = 0; x < dim; ++x )
							for( int y = 0; y < x; ++y )
								if( ok( x, y, dim, i ) )
									swap( brd[ x ][ y ], brd[ y ][ x ] );
						break;
					case 4:
						for( int x = 0; x < dim; ++x )
							for( int y = 0; y < dim - x; ++y )
								if( ok( x, y, dim, i ) )
									swap( brd[ x ][ y ], brd[ dim - y - 1 ][ dim - x - 1 ] );
						break;
				}
		for( int i = 0; i < dim; ++i )
			for( int j = 0; j < dim; ++j )
				printf( "%d%c", brd[ i ][ j ], j == dim - 1? '\n' : ' ' );
	}
}
