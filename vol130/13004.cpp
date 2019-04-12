#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void prev( char* s )
{
	for( int i = strlen( s ) - 1; i >= 0; --i )
	{
		int count[ 10 ] = { 0 };

		for( int j = 0; j <= i; ++j )
			++count[ s[ j ] - '0' ];

		if( !s[ i + 1 ] && all_of( count, count + 10, [] ( int n ) { return n <= 2; } ) )
			return;

		--count[ s[ i ] - '0' ];
		if( any_of( count, count + 10, [] ( int n ) { return n > 2; } ) )
			continue;

		for( int j = s[ i ] - '0' - 1; j >= 0; --j )
			if( count[ j ] < 2 )
			{
				++count[ j ];
				s[ i ] = j + '0';
				for( int k = i + 1; s[ k ]; ++k )
					for( int l = 9; l >= 0; --l )
						if( count[ l ] < 2 )
						{
							++count[ l ];
							s[ k ] = l + '0';
							break;
						}
				return;
			}
	}
}

int main()
{
	for( char s[ 20 ] = { 0 }; gets( s ); puts( s + ( *s == '0' ) ) )
		prev( s );
}
