#include<cstdio>
#include<cstring>
#include<algorithm>
#define INT_MAX 9999
int isPand( char* begin, char* end )
{
	for( ; begin < end; ++begin, --end )
		if( *begin != *end )
			return false;
	return true;
}

int main()
{
	int t;
	char str[ 1001 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%s", str );
		int len = strlen( str ), opt[ len ];
		*opt = 1;
		for( int i = 1; i < len; ++i )
			opt[ i ] = INT_MAX;
		for( int n = 1; n < len; ++n )
			for( int i = 0; i <= n && opt[ n ] != 1; ++i )
				if( isPand( str+i, str+n ) )
					opt[ n ] = std::min( opt[ n ], 1 + ( i? opt[ i-1 ] : 0 ) );
		printf( "%d\n", opt[ len-1 ] );
	}

	return 0;
}