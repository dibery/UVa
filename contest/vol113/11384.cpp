#include<cstdio>
#include<algorithm>

int main()
{
	int pow2[ 31 ] = { 1 };
	for( int i = 1; i < 31; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;

	for( int n; scanf( "%d", &n ) == 1; )
		printf( "%d\n", std::upper_bound( pow2, pow2+31, n ) - pow2 );
}
