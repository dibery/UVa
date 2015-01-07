#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
	int n, m, t = 0;

	while( scanf( "%d%*c", &n ) && n )
	{
		char ans[ 100 ][ 120 ] = { 0 }, out[ 100 ][ 120 ] = { 0 },
				 wbans[ 12001 ] = { 0 }, wbout[ 12001 ] = { 0 };
		for( int i = 0; i < n; ++i )
			gets( ans[ i ] );
		scanf( "%d%*c", &m );
		for( int i = 0; i < m; ++i )
			gets( out[ i ] );

		bool ac = n == m;
		for( int i = 0; i < n && ac; ++i )
			ac &= !strcmp( ans[ i ], out[ i ] );
		if( ac )
			printf( "Run #%d: Accepted\n", ++t );
		else
		{
			for( int i = 0, size = 0; i < n; ++i )
				for( int j = 0; ans[ i ][ j ]; ++j )
					if( isdigit( ans[ i ][ j ] ) )
						wbans[ size++ ] = ans[ i ][ j ];
			for( int i = 0, size = 0; i < m; ++i )
				for( int j = 0; out[ i ][ j ]; ++j )
					if( isdigit( out[ i ][ j ] ) )
						wbout[ size++ ] = out[ i ][ j ];
			printf( "Run #%d: %s\n", ++t, !strcmp( wbans, wbout )? "Presentation Error" : "Wrong Answer" );
		}
	}
}
