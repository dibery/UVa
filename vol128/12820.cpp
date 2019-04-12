#include<bits/stdc++.h>

int check( char* s )
{
	int time[ 26 ] = { 0 }, diff = 0;

	while( *s )
		++time[ *s++ - 'a' ];
	for( int i = 0; i < 26; ++i )
		diff += time[ i ] != 0;
	if( diff < 2 )
		return 0;
	for( int i = 0; i < 26; ++i )
		if( time[ i ] )
			for( int j = i+1; j < 26; ++j )
				if( time[ i ] == time[ j ] )
					return 0;
	return 1;
}

int main()
{
	for( int size, t = 0, ans = 0; scanf( "%d", &size ) == 1; ans = 0 )
	{
		for( char s[ 31 ]; size--; ans += check( s ) )
			scanf( "%s", s );
		printf( "Case %d: %d\n", ++t, ans );
	}
}
