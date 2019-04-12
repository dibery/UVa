#include<cstdio>
#include<cstring>

const int S = 200001;
int N, T, ohm[ S ], bit[ S ];
char cmd[ 4 ];

int main()
{
	while( scanf( "%d", &N ) && N )
	{
		if( T++ )
			puts( "" );
		printf( "Case %d:\n", T );
		memset( bit, 0, sizeof( bit ) );

		for( int i = 1; i <= N; ++i )
			scanf( "%d", ohm + i );
		for( int i = 1; i <= N; ++i )
			for( int p = i; p <= N; p += p & -p )
				bit[ p ] += ohm[ i ];

		for( int a, b; scanf( "%s", cmd ) && strcmp( cmd, "END" ); )
			if( *cmd == 'S' )
			{
				scanf( "%d %d", &a, &b );
				for( int diff = b - ohm[ a ], p = a; p <= N; p += p & -p )
					bit[ p ] += diff;
				ohm[ a ] = b;
			}
			else
			{
				scanf( "%d %d", &a, &b );
				int Sa = 0, Sb = 0;
				while( b )
					Sb += bit[ b ], b -= b & -b;
				for( --a; a; )
					Sa += bit[ a ], a -= a & -a;
				printf( "%d\n", Sb - Sa );
			}
	}
}
