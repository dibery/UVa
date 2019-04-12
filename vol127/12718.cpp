#include<bits/stdc++.h>

int calc( char* b )
{
	int time[ 26 ] = { 0 }, odd = 0, ret = 0;

	for( char* e = b; *e; ++e )
	{
		int p = *e - 'a';
		if( time[ p ] % 2 == 0 )
			++odd;
		else
			--odd;
		if( odd <= 1 )
			++ret;
		++time[ p ];
	}
	return ret;
}

int main()
{
	int t;
	char str[ 1001 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%s", str );
		int ans = 0;
		for( char* b = str; *b; ++b )
			ans += calc( b );
		printf( "Case %d: %d\n", n, ans );
	}
}
