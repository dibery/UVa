#include<cstdio>
#include<algorithm>
using namespace std;
#define NPOS (-1)

int find( char* f, char* t, int offset, char F, char T )
{
	for( ; f[ offset ]; ++offset )
		if( f[ offset ] == F && t[ offset ] == T )
			return offset;
	return NPOS;
}

int count( char* f, char* t, int offset, char F, char T )
{
	int q = 0;
	for( ; f[ offset ]; ++offset )
		if( f[ offset ] == F && t[ offset ] == T )
			++q;
	return q;
}

int main()
{
	int t;
	char from[ 101 ], to[ 101 ];

	scanf( "%d\n", &t );
	for( int n = 1; n <= t; ++n )
	{
		bool wrong = false;
		int act = 0;
		gets( from );
		gets( to );

		for( int i = 0; from[ i ] && !wrong; ++i )
			if( from[ i ] != to[ i ] )
				if( from[ i ] == '0' )
					if( find( from, to, i, '1', '0' ) == NPOS )
						from[ i ] = '1', ++act;
					else
						swap( from[ i ], from[ find( from, to, i, '1', '0' ) ] ), ++act;
				else if( from[ i ] == '1' )
					if( find( from, to, i, '0', '1' ) != NPOS )
						swap( from[ i ], from[ find( from, to, i, '0', '1' ) ] ), ++act;
					else if( find( from, to, i, '?', '1' ) != NPOS )
						from[ find( from, to, i, '?', '1' ) ] = '1', from[ i ] = '0', act += 2;
					else
						wrong = true;
				else // '?'
					if( to[ i ] == '0' )
						if( count( from, to, i, '1', '0' ) <= count( from, to, i, '0', '1' ) )
							from[ i ] = to[ i ], ++act;
						else
							from[ i ] = '0', ++act;
					else // '1'
						if( count( from, to, i, '1', '0' ) <= count( from, to, i, '0', '1' ) )
							from[ i ] = to[ i ], ++act;
						else if( find( from, to, i, '1', '0' ) != NPOS )
							from[ find( from, to, i, '1', '0' ) ] = '0', from[ i ] = '1', act += 2;
						else
							from[ i ] = to[ i ], ++act;
		printf( "Case %d: %d\n", n, wrong? -1 : act );
	}
}
