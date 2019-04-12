#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

pair<int,int> judge( int size, int* num, int* ans )
{
	int A = 0, B = 0;
	bool used[ size ];
	fill( used, used+size, false );

	for( int i = 0; i < size; ++i )
		if( num[ i ] == ans[ i ] )
			++A, used[ i ] = true;
	for( int i = 0; i < size; ++i )
		if( num[ i ] != ans[ i ] )
			for( int j = 0; j < size; ++j )
				if( num[ i ] == ans[ j ] && !used[ j ] )
				{
					++B;
					used[ j ] = true;
					break;
				}
	return pair<int,int> ( A, B );
}

int main()
{
	int t, a, b, n[ 10 ], ans[ 10 ], len;
	char tmp[ 10 ], test[ 10 ];

	for( scanf( "%d", &t ); t; --t )
	{
		int sol = 0;
		scanf( "%s %d %d", test, &a, &b );
		len = strlen( test );
		for( int i = 0; i < len; ++i )
			n[ i ] = test[ i ] - '0';

		for( int i = 1 * pow( 10, len - 1 ), lim = pow( 10, len ); i < lim; ++i )
		{
			sprintf( tmp, "%d", i );
			for( int i = 0; i < len; ++i )
				ans[ i ] = tmp[ i ] - '0';
			if( strchr( tmp, '0' ) == NULL )
			{
				pair<int,int> r = judge( len, n, ans );
				if( r.first == a && r.second == b )
					++sol;
			}
		}
		printf( "%d\n", sol );
	}
}
