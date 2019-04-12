#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
	int size, begin, m, n, t = 0;

	while( scanf( "%d", &size ) && size )
	{
		int aps[ 100 ][ 100 ] = { { 0 } }, ans = 0, len = 0;
		scanf( "%d", &begin );
		--begin;
		while( scanf( "%d %d", &m, &n ) && m+n )
			aps[ m-1 ][ n-1 ] = 1;
		for( int m = 0; m < size; ++m )
			for( int b = 0; b < size; ++b )
				for( int e = 0; e < size; ++e )
					if( aps[ b ][ m ] && aps[ m ][ e ] )
						aps[ b ][ e ] = std::max( aps[ b ][ e ], aps[ b ][ m ] + aps[ m ][ e ] );
		for( int i = 0; i < size; ++i )
			if( aps[ begin ][ i ] > len )
				len = aps[ begin ][ i ], ans = i;
		printf( "Case %d: The longest path from %d has length %d, finishing at %d.\n\n", ++t, begin+1, len, ans+1 );
	}
}
