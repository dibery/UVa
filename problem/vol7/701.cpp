#include<cstdio>
#include<cmath>
const double inc = log2( 10 );

int main()
{
	for( unsigned x, ans; scanf( "%u", &x ) == 1; )
	{
		double lx = log2( x ), ly = log2( x + 1 );
		for( ans = log10( x ) + 2; int( lx + inc * ans ) == int( ly + inc * ans ); ++ans );
		printf( "%d\n", int( ly + inc * ans ) );
	}
}
