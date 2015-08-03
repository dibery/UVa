#include<cstdio>
#include<algorithm>

int main()
{
	for( int a, b; scanf( "%d", &a ) == 1; )
	{
		int grp[ 100001 ] = { 0 }, refuse = 0, M = -1;

		for( int i = 0; i < 100001; ++i )
			grp[ i ] = i;
		while( a != -1 )
		{
			scanf( "%d", &b );
			M = std::max( M, std::max( a, b ) );
			if( grp[ a ] == grp[ b ] )
				++refuse;
			else
				for( int i = 0, id = grp[ b ]; i <= M; ++i )
					if( grp[ i ] == id )
						grp[ i ] = grp[ a ];
			scanf( "%d", &a );
		}
		printf( "%d\n", refuse );
	}
}
