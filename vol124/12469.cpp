#include<cstdio>
#include<algorithm>

bool win[ 1001 ][ 1001 ];

int main()
{
	for( int i = 1, j; i <= 1000; ++i ) // total
	{
		for( j = 1; j <= i && !win[ i ][ j ]; ++j ) // max one can take
			for( int k = 1; k <= j && !win[ i ][ j ]; ++k ) // take k stones
				if( !win[ i - k ][ std::min( 2 * k, i - k ) ] )
					win[ i ][ j ] = true;
		while( j <= i )
			if( win[ i ][ j ] )
				win[ i ][ ++j ] = true;
	}
	for( int n; scanf( "%d", &n ) && n; )
		puts( win[ n ][ n - 1 ]? "Alicia" : "Roberto" );
}
