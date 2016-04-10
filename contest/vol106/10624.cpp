#include<cstdio>

int mod( char s[], int len )
{
	int res = 0;
	for( int i = 0; i < len; ++i )
		res = ( res * 10 + s[ i ] - '0' ) % len;
	return res;
}

bool find( int check, int digit, char s[], int depth = 1 )
{
	if( depth > digit )
		return true;
	int now = depth - 1;
	for( s[ now ] = '0' + ( depth == 1 ); s[ now ] <= '9'; ++s[ now ] )
		if( depth < check || mod( s, depth ) == 0 )
			if( find( check, digit, s, depth + 1 ) )
				return true;
	return false;
}

int main()
{
	int t, check, digit;

	scanf( "%d", &t );
	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d %d", &check, &digit );
		char s[ 50 ] = { 0 };
		printf( "Case %d: %s\n", i, find( check, digit, s )? s : "-1" );
	}
}
