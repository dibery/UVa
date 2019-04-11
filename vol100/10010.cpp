#include<cstdio>
#include<cstring>
#include<cctype>
bool match( char field[ 50 ][ 51 ], char query[], int y, int x, int h, int w, int setx, int sety )
{
	for( int i = 0; i < strlen( query ); ++i )
	{
		if( x + setx*i < 0 || y + sety*i < 0 || x + setx*i >= w || y + sety*i >= h )
			return false;
		if( tolower( field[ y + sety*i ][ x + setx*i ] ) != tolower( query[ i ] ) )
			return false;
	}
	return true;
}
int find( char field[ 50 ][ 51 ], char query[], int h, int w )
{
	for( int i = 0; i < h; ++i )
		for( int j = 0; j < w; ++j )
			for( int setx = -1; setx <= 1; ++setx )
				for( int sety = -1; sety <= 1; ++sety )
					if( match( field, query, i, j, h, w, setx, sety ) )
					return i*100 + j;
}

int main()
{
	int t, width, height, query;
	char field[ 50 ][ 51 ] = { 0 }, str[ 51 ] = { 0 };
	scanf( "%d", &t );

	for( int i = 1; i <= t; ++i )
	{
		scanf( "%d %d", &height, &width );
		for( int a = 0; a < height; ++a )
			scanf( "%s", field[ a ] );
		scanf( "%d", &query );
		for( int a = 0; a < query; ++a )
		{
			scanf( "%s", str );
			int ans = find( field, str, height, width );
			printf( "%d %d\n", ans / 100 + 1, ans % 100 + 1, height, width );
		}
		if( i != t )
			puts( "" );
	}
	return 0;
}
