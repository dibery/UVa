#include<bits/stdc++.h>
using namespace std;

int main()
{
	char v[] = "AUEOI", c[] = "JSBKTCLDMVNWFXGPYHQZR";
	int t, len;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int show[ 26 ] = { 0 }, C[ 215 ] = { 0 }, V[ 215 ] = { 0 };
		char sc[ 215 ] = { 0 }, sv[ 215 ] = { 0 };

		scanf( "%d", &len );
		for( int i = 0; i < len; ++i )
			if( i & 1 ) //c
				++show[ c[ C[ i ] = find_if( c, c+21, [ show ] ( char c ) { return show[ c-'A' ] < 5; } ) - c ] - 'A' ];
			else
				++show[ v[ V[ i ] = find_if( v, v+5, [ show ] ( char c ) { return show[ c-'A' ] < 21; } ) - v ] - 'A' ];

		printf( "Case %d: ", n );
		for( int i = 0; i < len; ++i )
			if( i & 1 )
				sc[ i >> 1 ] = c[ C[ i ] ];
			else
				sv[ i >> 1 ] = v[ V[ i ] ];
		sort( sc, sc + strlen( sc ) );
		sort( sv, sv + strlen( sv ) );
		for( int i = 0; i < len; ++i )
			putchar( i & 1? sc[ i >> 1 ] : sv[ i >> 1 ] );
		puts( "" );
	}
}
