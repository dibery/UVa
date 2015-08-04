#include<cstdio>
#include<cstdlib>

int main()
{
	int t, size, next[ 20001 ], query, from, to;
	char in[ 30 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d\n", &size );
		for( int i = 1; i <= size; ++i )
			next[ i ] = i;

		while( gets( in ) && *in != 'O' )
			if( *in == 'E' )
			{
				int ans = 0;
				sscanf( in, "%*c %d", &query );
				while( query != next[ query ] )
					ans += abs( query - next[ query ] ) % 1000, query = next[ query ];
				printf( "%d\n", ans );
			}
			else // 'I'
			{
				sscanf( in, "%*c %d %d", &from, &to );
				next[ from ] = to;
			}
	}
}
