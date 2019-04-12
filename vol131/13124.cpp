#include<bits/stdc++.h>
using namespace std;

struct node
{
	char times[ 26 ], len;
	bool found;
	node()
	{
		memset( times, found = len = 0, sizeof( times ) );
		char s[ 101 ];
		scanf( "%s", s );
		for( len = 0; s[ len ]; ++len )
			++times[ s[ len ] - 'a' ];
	}
	int get( char *s ) { return memcmp( times, s, sizeof( times ) ); }
	bool operator< ( const node& n ) const { return *this < n.times; }
	bool operator< ( const char* s ) const { return memcmp( times, s, sizeof( times ) ) < 0; }
	bool operator== ( char* s ) const { return memcmp( times, s, sizeof( times ) ) == 0; }
};

void locate( node* n, int B, int E, char* pattern, int stat[] )
{
	int begin = B, end = E, mid = begin + end >> 1, c = n[ mid ].get( pattern );
	for( ; begin < end; c = n[ mid = begin + end >> 1 ].get( pattern ) )
		if( !c )
			break;
		else if( c < 0 )
			begin = mid + 1;
		else
			end = mid - 1;
	if( !n[ mid ].found && n[ mid ] == pattern )
	{
		for( int i = mid; i <= E && n[ i ] == n[ mid ].times; ++i )
			n[ i ].found = true, --stat[ n[ mid ].len ];
		for( int i = mid - 1; i >= 0 && n[ i ] == n[ mid ].times; --i )
			n[ i ].found = true, --stat[ n[ mid ].len ];
	}
}

int main()
{
	char brd[ 100 ][ 101 ] = { { 0 } };
	for( int r, c, w; scanf( "%d %d %d", &r, &c, &w ) == 3; )
	{
		int stat[ 101 ] = { 0 };
		for( int i = 0; i < r; ++i )
			scanf( "%s", brd[ i ] );

		node dict[ w ];
		sort( dict, dict + w );
		for( int i = 0; i < w; ++i )
			++stat[ dict[ i ].len ];

		for( int i = 0; i < r; ++i )
			for( int j = 0; j < c; ++j )
			{
				char h[ 26 ] = { 0 }, v[ 26 ] = { 0 }, d[ 26 ] = { 0 }, d2[ 26 ] = { 0 };
				for( int k = j; k < c; ++k )
				{
					++h[ brd[ i ][ k ] - 'a' ];
					if( stat[ k - j + 1 ] )
						locate( dict, 0, w - 1, h, stat );
				}
				for( int k = i; k < r; ++k )
				{
					++v[ brd[ k ][ j ] - 'a' ];
					if( stat[ k - i + 1 ] )
						locate( dict, 0, w - 1, v, stat );
				}
				for( int k = i, l = j; k < r && l < c; ++k, ++l )
				{
					++d[ brd[ k ][ l ] - 'a' ];
					if( stat[ k - i + 1 ] )
						locate( dict, 0, w - 1, d, stat );
				}
				for( int k = i, l = j; k < r && l >= 0; ++k, --l )
				{
					++d2[ brd[ k ][ l ] - 'a' ];
					if( stat[ k - i + 1 ] )
						locate( dict, 0, w - 1, d2, stat );
				}
			}
		printf( "%llu\n", count_if( dict, dict + w, [] ( const node& n ) { return n.found; } ) );
	}
}
