#include<cstdio>
#include<cstring>

long long way[ 26 ][ 26 ];

long long ans( int h, int w )
{
	if( way[ h ][ w ] != -1 )
		return way[ h ][ w ];
	if( h == 1 || w == 1 )
		return way[ h ][ w ] = 1;
	long long a = 0;
	for( int i = 1; i <= h; ++i )
		a += ans( w - 1, i );
	return way[ h ][ w ] = a;
}

int main()
{
	int h, w;
	memset( way, -1, sizeof( way ) );
	for( scanf( "%*d" ); scanf( "%d %d", &h, &w ) == 2; )
		printf( "%lld\n", ans( h, w ) );
}
