#include<cstdio>
#include<algorithm>

int main()
{
	int method[ 10000 ], t, n, *p;

	for( int i = 0; i < 10000; ++i )
		method[ i ] = ( i + 2 ) * ( i + 1 ) / 2;
	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); )
		if( *( p = std::lower_bound( method, method + 10000, n ) ) == n )
			printf( "%d\n", p - method );
		else
			puts( "No solution" );
}
