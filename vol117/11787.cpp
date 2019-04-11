#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
const char s[] = "BUSPFTM";

bool order( char* str )
{
	bool ok = true;
	for( int i = 1; str[ i ]; ++i )
		ok &= strchr( s, str[ i ] ) >= strchr( s, str[ i - 1 ] );
	if( ok )
		return true;
	ok = true;
	for( int i = 1; str[ i ]; ++i )
		ok &= strchr( s, str[ i ] ) <= strchr( s, str[ i - 1 ] );
	return ok;
}

bool time( char* str )
{
	for( char c: s )
		if( std::count( str, str + strlen( str ), c ) > 9 )
			return false;
	return true;
}

int main()
{
	char str[ 501 ] = { 0 };
	
	for( scanf( "%*d" ); scanf( "%s", str ) == 1; )
	{
		if( order( str ) && time( str ) )
		{
			int ans = 0;
			for( int i = 0; str[ i ]; ++i )
				ans += pow( 10, strchr( s, str[ i ] ) - s ) + 1e-9;
			printf( "%d\n", ans );
		}
		else
			puts( "error" );
	}
}
