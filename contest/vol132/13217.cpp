#include<bits/stdc++.h>

int main()
{
	double f[ 5 ] = { sqrt( 2 ) + sqrt( 3 ) + sqrt( 6 ) };

	for( int i = 1; i < 5; ++i )
		f[ i ] = ( f[ i - 1 ] * f[ i - 1 ] - 5 ) / ( 2 * f[ i - 1 ] + 4 );

	for( char in[ 2000 ], c; gets( in ) && ( c = in[ strlen( in ) - 1 ] ); )
		printf( "%.10f\n", strlen( in ) == 1 && c < '3'? f[ c - '0' ] : f[ 3 + ( ( c - '0' ) % 2 == 0 ) ] );
}
