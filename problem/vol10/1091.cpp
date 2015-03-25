#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-9;

const char *enc[] = { "00001", "10001", "01001", "11000", "00101", "10100", "01100", "00011", "10010", "10000", "00100", "00110" };

void ok( double in[], int size, double& low )
{
	for( low = 0.01; low <= 106; low += 0.01 )
		if( all_of( in, in+size, [ low ] ( double i ) { return i >= low * 0.95 - eps && i <= low * 1.05 + eps || i >= low * 1.9 -eps && i <= low * 2.1 + eps; } ) )
			return; // The lower bound is found
	low = -1; // Not found, set to -1
}

char* judge( char* s )
{
	static char result[ 4 ][ 40 ] = { "bad code", "bad C", "bad K", "" }; // [3] is for decoding
	int len = strlen( s ), size = (len+1) / 6, code_size = size-4, sum = 0;

	memset( result[ 3 ], 0, 40 );
	for( char* p = s+6; *(p+6); p += 6 )
	{
		int c = 0;
		for( c = 0; c <= 11; ++c )
			if( !strncmp( p, enc[ c ], 5 ) )
				break; // The current code
		if( c > 11 || p[ 5 ] == '1' )
			return *result; // Not matched, or the seperator is wide
		if( c == 11 && p[ 5 ] )
			return *result; // There's data after stop mark
		result[ 3 ][ (p-s) / 6 ] = c + '0';
	}

	// C
	for( int i = 1; i <= code_size; ++i )
		sum += ( ( code_size - i ) % 10 + 1 ) * ( result[ 3 ][ i ] - '0' );
	sum %= 11;
	if( strncmp( s + 6*code_size + 6, enc[ sum ], 5 ) )
		return result[ 1 ];

	// K
	sum = 0;
	for( int i = 1; i <= code_size+1; ++i )
		sum += ( ( code_size - i + 1 ) % 9 + 1 ) * ( result[ 3 ][ i ] - '0' );
	sum %= 11;
	if( strncmp( s + 6*code_size + 12, enc[ sum ], 5 ) )
		return result[ 2 ];
	
	// Ready to print this code
	for( int i = 0; i < code_size; ++i )
		result[ 3 ][ i ] = result[ 3 ][ i+1 ] == ':'? '-' : result[ 3 ][ i+1 ];
	result[ 3 ][ code_size ] = 0;
	return result[ 3 ];
}

int main()
{
	int len, t = 0;
	double in[ 150 ], low;

	while( scanf( "%d", &len ) && len )
	{
		char code[ 151 ] = { 0 };

		for( int i = 0; i < len; ++i )
			scanf( "%lf", in+i );
		ok( in, len, low ); // Find the lower bound of narrow bars

		transform( in, in+len, code, [ low ] ( double i ) { return ( i >= low*1.9 ) + '0'; } ); // Make code
		if( strncmp( code, enc[ 11 ], 5 ) )
			reverse( code, code+len );

		if( len < 29 || low == -1 || ( len+1 ) % 6 || strncmp( code, enc[ 11 ], 5 ) || strcmp( code+len-5, enc[ 11 ] ) )
			printf( "Case %d: bad code\n", ++t );
		else
			printf( "Case %d: %s\n", ++t, judge( code ) );
	}
}
