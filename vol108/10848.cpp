#include<bits/stdc++.h>
using namespace std;

bool p1( char* s, char* a, char* n, char* b )
{
	if( count( s, s + strlen( s ), ' ' ) != 2 )
		return false;
	replace( s, s + strlen( s ), ' ', '\0' );
	sscanf( s, "%s", a );
	sscanf( s += strlen( s ) + 1, "%s", n );
	sscanf( s + strlen( s ) + 1, "%s", b );

	if( strlen( a ) > 1000 || strlen( b ) > 2000 || !all_of( n, n + strlen( n ), ::isdigit ) || !all_of( a, a + strlen( a ), ::islower ) || !all_of( b, b + strlen( b ), ::islower ) || atoi( n ) > 1000 || atoi( n ) < 0 )
		return false;
	return true;
}

bool p2( char* s )
{
	char r[ 5000 ] = { 0 };
	reverse_copy( s, s + strlen( s ), r );
	return !strcmp( s, r );
}

bool p3( char* a, char* b )
{
	bool show[ 26 ] = { false };
	while( *a )
		show[ *a++ - 'a' ] = true;
	while( *b )
		show[ *b++ - 'a' ] = false;
	return find( show, show+26, true ) == show+26;
}

bool p4( char* a, char* b )
{
	int show[ 26 ] = { 0 };
	while( *a )
		++show[ *a++ - 'a' ];
	while( *b )
		--show[ *b++ - 'a' ];
	return all_of( show, show+26, [] ( int n ) { return n <= 0; } );
}

bool p5( char* a, char* b )
{
	for( ; *a && *b; ++a, ++b )
		while( *a != *b && *b )
			++b;
	return !*a;
}

int main()
{
	for( char s[ 5000 ], a[ 5000 ], b[ 5000 ], n[ 5000 ]; gets( s ); )
	{
		bool status[ 7 ];
		char out[ 8 ] = { 0 };
		memset( a, 0, 5000 );
		memset( b, 0, 5000 );

		status[ 0 ] = p1( s, a, n, b );
		status[ 1 ] = *status && p2( b );
		status[ 2 ] = *status && p3( a, b );
		status[ 3 ] = *status && p4( a, b );
		status[ 4 ] = *status && p5( a, b );
		status[ 5 ] = *status && strlen( a ) + atoi( n ) == strlen( b );
		status[ 6 ] = *status && strlen( a ) > atoi( n );

		for( int i = 0; i < 7; ++i )
			out[ i ] = status[ i ]? 'T' : 'F';
		printf( "%s The solution is %saccepted\n", out, strcmp( out, "TTTTTTT" )? "not " : "" );
	}
}
