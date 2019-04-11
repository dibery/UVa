#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

void out( char* s, int req[], int printed, int size, char str[], bool& msg, int dep = 0 )
{
	if( dep == size )
		puts( str+1 ), msg = true;
	else
		for( int i = 0; s[ i ]; ++i )
			if( !( printed & 1 << s[ i ] - 'A' ) && ( req[ s[ i ] - 'A' ] & printed ) == req[ s[ i ] - 'A' ] )
			{
				sprintf( str + dep * 2, " %c", s[ i ] );
				out( s, req, printed | 1 << s[ i ] - 'A', size, str, msg, dep+1 );
			}
}

int main()
{
	int t;

	for( scanf( "%d\n", &t ); t--; )
	{
		int req[ 26 ] = { 0 };
		bool msg = false;
		char list[ 99 ] = { 0 }, st[ 500 ] = { 0 }, buffer[ 99 ] = { 0 };

		gets( list );
		*remove( list, list + strlen( list ), ' ' ) = 0;
		sort( list, list + strlen( list ) );
		for( char* p = gets( st ), a, b; *p; p += 4 )
			req[ p[ 2 ] - 'A' ] |= 1 << p[ 0 ] - 'A';
		out( list, req, 0, strlen( list ), buffer, msg );
		if( !msg )
			puts( "NO" );
		if( t )
			puts( "" );
		gets( list );
	}
}
