#include<cstdio>
#include<stack>

int main()
{
	int t;
	char s[ 1000 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%s", s );
		std::stack<char> dfs;
		int edge[ 26 ] = { 0 };

		for( int i = 0; s[ i ]; ++i )
			if( dfs.empty() )
				dfs.push( s[ i ] );
			else if( dfs.top() == s[ i ] )
				dfs.pop();
			else
			{
				++edge[ dfs.top() - 'A' ];
				dfs.push( s[ i ] );
				++edge[ dfs.top() - 'A' ];
			}
		printf( "Case %d\n", n );
		for( int i = 0; i < 26; ++i )
			if( edge[ i ] )
				printf( "%c = %d\n", 'A' + i, edge[ i ] );
	}
}
