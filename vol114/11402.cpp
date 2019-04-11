#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

typedef unsigned long long ull;
char buffer[ 1024001 ];
ull stat[ 16000 ], bit_one[ 256 ];

int get_one( ull n )
{
	int ans = 0;
	while( n )
		ans += bit_one[ n & 255ll ], n >>= 8;
	return ans;
}

int main()
{
	int T, pair, repeat, query, begin, end;
	char pattern[ 99 ], type, *p = buffer;

	for( int i = 1; i < 256; ++i )
		bit_one[ i ] = 1 + bit_one[ i ^ i & -i ];

	scanf( "%d", &T );
	for( int n = 1, Q = 0; n <= T; ++n, p = buffer, Q = 0 )
	{
		memset( buffer, 0, sizeof( buffer ) );
		memset( stat, 0, sizeof( stat ) );
		for( scanf( "%d", &pair ); pair--; )
		{
			scanf( "%d %s", &repeat, pattern );
			for( ; repeat--; p += strlen( pattern ) )
				sprintf( p, pattern );
		}
		for( int i = 0; buffer[ i ]; ++i )
			if( buffer[ i ] == '1' )
				stat[ i / 64 ] |= 1ll << i % 64;
		scanf( "%d%*c", &query );
		printf( "Case %d:\n", n );
		while( query-- && scanf( "%c %d %d%*c", &type, &begin, &end ) )
		{
			int front = begin + ( 64 - begin % 64 ) % 64, back = end - end % 64;
			if( type == 'F' )
			{
				if( back > front )
					memset( stat + front / 64, -1, back - front >> 3 );
				front = min( front, end );
				back = max( back, begin );
				while( begin < front )
					stat[ begin / 64 ] |= 1ll << begin % 64, ++begin;
				while( back <= end )
					stat[ back / 64 ] |= 1ll << back % 64, ++back;
			}
			else if( type == 'E' )
			{
				if( back > front )
					memset( stat + front / 64, 0, back - front >> 3 );
				front = min( front, end );
				back = max( back, begin );
				while( begin < front )
					stat[ begin / 64 ] &= ~( 1ll << begin % 64 ), ++begin;
				while( back <= end )
					stat[ back / 64 ] &= ~( 1ll << back % 64 ), ++back;
			}
			else if( type == 'I' )
			{
				for( int i = front >> 6; i < back >> 6; ++i )
					stat[ i ] = ~stat[ i ];
				front = min( front, end );
				back = max( back, begin );
				if( begin / 64 != end / 64 )
					while( begin < front )
						stat[ begin / 64 ] ^= 1ll << begin % 64, ++begin;
				while( back <= end )
					stat[ back / 64 ] ^= 1ll << back % 64, ++back;
			}
			else
			{
				int ans = 0;
				for( int i = front >> 6; i < back >> 6; ++i )
					ans += get_one( stat[ i ] );
				front = min( front, end );
				back = max( back, begin );
				if( begin / 64 != end / 64 )
					while( begin < front )
						ans += ( stat[ begin / 64 ] & 1ll << begin % 64 ) != 0, ++begin;
				while( back <= end )
					ans += ( stat[ back / 64 ] & 1ll << back % 64 ) != 0, ++back;
				printf( "Q%d: %d\n", ++Q, ans );
			}
		}
	}
}
