#include<bits/stdc++.h>
using namespace std;

struct trie
{
	int count, next_idx[ 63 ];
} data[ 4000001 ];

inline int codec( char c )
{
	if( isdigit( c ) )
		return c - '0';
	if( isupper( c ) )
		return c - 'A' + 10;
	return c? c - 'a' + 36 : 62;
}

int main()
{
	for( int size, t = 0; scanf( "%d", &size ) && size; )
	{
		int ID = 0;
		long long ans = 0;
		memset( data, 0, sizeof( data ) );
		for( char s[ 1001 ]; size-- && scanf( "%s", s ); )
			for( int i = 0, pos = 0; ; ++i )
			{
				int letter = codec( s[ i ] ), &next_pos = data[ pos ].next_idx[ letter ];
				if( !next_pos )
					next_pos = ++ID;
				ans += ( data[ pos ].count - data[ next_pos ].count ) * ( i * 2 + 1 );
				++data[ pos ].count;
				pos = next_pos;
				if( !s[ i ] )
				{
					ans += ( i * 2 + 2 ) * data[ pos ].count;
					++data[ pos ].count;
					break;
				}
			}
		printf( "Case %d: %lld\n", ++t, ans );
	}
}
