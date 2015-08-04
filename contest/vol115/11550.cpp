#include<cstdio>

int main()
{
	int t, m, n, brd[ 8 ][ 28 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &m, &n );
		for( int i = 0; i < m; ++i )
			for( int j = 0; j < n; ++j )
				scanf( "%d", brd[ i ] + j );
		bool ok = true, pos[ 8 ][ 8 ] = { { false } };
		for( int i = 0; i < n; ++i )
		{
			int p = -1, q = -1;
			for( int j = 0; j < m; ++j )
				if( brd[ j ][ i ] )
					if( p == -1 )
						p = j;
					else if( q == -1 )
						q = j;
					else
						ok = false;
			if( p == -1 || q == -1 || pos[ p ][ q ] )
				ok = false;
			else
				pos[ p ][ q ] = true;
		}
		puts( ok? "Yes" : "No" );
	}
}
