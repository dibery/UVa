#include<cstdio>
#include<algorithm>

int main()
{
	scanf( "%*d" );
	for( int p, x[ 50000 ], y[ 50000 ]; scanf( "%*d %*d %d", &p ) == 1; )
	{
		for( int i = 0; i < p; ++i )
			scanf( "%d %d", x + i, y + i );
		std::sort( x, x + p );
		std::sort( y, y + p );
		printf( "(Street: %d, Avenue: %d)\n", x[ ( p - 1 ) / 2 ], y[ ( p - 1 ) / 2 ] );
	}
}
