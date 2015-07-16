#include<cstdio>
#include<cstring>

bool ok( char* s, int Try )
{
	for( int i = Try; s[ i ]; ++i )
		if( s[ i ] != s[ i % Try ] )
			return false;
	return true;
}

int main()
{
	int t;
	char s[ 1001 ];

	for( scanf( "%d%*c", &t ); t--; )
	{
		int ans = 0, l = strlen( gets( s ) );

		if( *s )
			for( ans = 1; ans <= l; ++ans )
				if( l % ans == 0 && ok( s, ans ) )
					break;
		printf( "%d\n", ans );
	}
}
