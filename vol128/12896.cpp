#include<cstdio>

int main()
{
	int t, len, button[ 100 ], time[ 100 ];
	char map[][ 5 ] = { " ", ".,?\"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

	for( scanf( "%d", &t ); t--; puts( "" ) )
	{
		scanf( "%d", &len );
		for( int i = 0; i < len; ++i )
			scanf( "%d", button + i );
		for( int i = 0; i < len; ++i )
			scanf( "%d", time + i );
		for( int i = 0; i < len; ++i )
			putchar( map[ button[ i ] ][ time[ i ] - 1 ] );
	}
}
