#include<cstdio>
#include<algorithm>

int hp[ 90000 ] = { 5 }, shp[ 110000 ], size = 1, ssize = 0, n;
bool isshp[ 1000002 ];

bool ishp( int n )
{
	for( int i = 0; hp[ i ] * hp[ i ] <= n; ++i )
		if( n % hp[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 9; i <= 200000; i += 4 )
		if( ishp( i ) )
			hp[ size++ ] = i;
	for( int i = 0; hp[ i ] < 1000; ++i )
		for( int j = i; hp[ i ] * hp[ j ] <= 1000001 && j < size; ++j )
			if( !isshp[ hp[ i ] * hp[ j ] ] )
			{
				isshp[ hp[ i ] * hp[ j ] ] = true;
				shp[ ssize++ ] = hp[ i ] * hp[ j ];
			}
	std::sort( shp, shp + ssize );

	while( scanf( "%d", &n ) && n )
		printf( "%d %d\n", n, std::upper_bound( shp, shp + ssize, n ) - shp );
}
