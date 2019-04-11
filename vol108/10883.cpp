#include<cstdio>
#include<cmath>

int main()
{
	int t, n;
	double fact[ 50001 ] = { 0 }, pow2[ 50001 ] = { 0 }, log2 = log10( 2 );

	for( int i = 1; i < 50001; ++i )
	{
		fact[ i ] = fact[ i - 1 ] + log10( i );
		pow2[ i ] = pow2[ i - 1 ] + log2;
	}

	scanf( "%d", &t );
	for( int T = 1; T <= t && scanf( "%d", &n ); ++T )
	{
		double sum = 0, in;
		for( int i = 0; i < n && scanf( "%lf", &in ); ++i )
			if( in > 0 )
				sum += pow( 10, log10( std::abs( in ) ) + fact[ n - 1 ] - fact[ i ] - fact[ n - 1 - i ] - pow2[ n - 1 ] );
			else if( in < 0 )
				sum -= pow( 10, log10( std::abs( in ) ) + fact[ n - 1 ] - fact[ i ] - fact[ n - 1 - i ] - pow2[ n - 1 ] );
		printf( "Case #%d: %.3f\n", T, sum );
	}
}
