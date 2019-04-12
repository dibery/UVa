#include<cstdio>
#include<climits>
#include<algorithm>

int main()
{
	int from, to, t = 0;

	while( scanf( "%d %d", &from, &to ) && from+to )
	{
		short adj[ 101 ][ 101 ] = { { 0 } };
		bool exist[ 101 ] = { false };
		double sum = 0;
		exist[ from ] = exist[ to ] = true;
		for( adj[ from ][ to ] = 1; scanf( "%d %d", &from, &to ) && from+to; exist[ from ] = exist[ to ] = true )
			adj[ from ][ to ] = 1;
		int total = std::count( exist, exist+101, true );
		for( int m = 0; m <= 100; ++m )
			for( int b = 0; b <= 100; ++b )
				for( int e = 0; e <= 100; ++e )
					if( exist[ m ] & exist[ b ] & exist[ e ] && adj[ b ][ m ] && adj[ m ][ e ] && b != e )
						if( adj[ b ][ e ] )
							adj[ b ][ e ] = std::min( adj[ b ][ e ], short( adj[ b ][ m ] + adj[ m ][ e ] ) );
						else
							adj[ b ][ e ] = adj[ b ][ m ] + adj[ m ][ e ];
		for( int i = 1; i <= 100; ++i )
			for( int j = 1; j <= 100; ++j )
				sum += adj[ i ][ j ];
		printf( "Case %d: average length between pages = %.3f clicks\n", ++t, sum / total / (total-1) );
	}
}
