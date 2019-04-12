#include<cstdio>
#include<cstring>
char dict[ 10000 ][ 26 ], query[ 26 ];
int ds, qs;

bool onewrong( char* a, char* b )
{
	if( strlen( a ) != strlen( b ) )
		return false;
	int mismatch = 0;
	for( int i = 0; a[ i ]; ++i )
		mismatch += a[ i ] != b[ i ];
	return mismatch == 1;
}

bool adjwrong( char*a , char* b )
{
	if( strlen( a ) != strlen( b ) )
		return false;
	int mismatch = 0, p;
	for( int i = 0; a[ i ]; ++i )
		if( a[ i ] != b[ i ] )
			++mismatch, p = i;
	if( mismatch != 2 )
		return false;
	return a[ p-1 ] == b[ p ] && a[ p ] == b[ p-1 ];
}

bool extract1( char* a, char* b ) // Extract a letter from a to get b
{
	if( strlen( a ) - 1 != strlen( b ) )
		return false;
	for( int i = 0, j; a[ i ]; ++i ) // The one to be extracted
	{
		for( j = 0; b[ j ]; ++j )
			if( b[ j ] != a[ j < i? j : j+1 ] )
				break;
		if( !b[ j ] )
			return true;
	}
	return false;
}

void judge()
{
	for( int i = 0; i < ds; ++i )
		if( !strcmp( dict[ i ], query ) )
		{
			printf( "%s is correct\n", query );
			return;
		}
	for( int i = 0; i < ds; ++i )
		if( extract1( dict[ i ], query ) || extract1( query, dict[ i ] ) ||
				onewrong( dict[ i ], query ) || adjwrong( dict[ i ], query ) )
		{
			printf( "%s is a misspelling of %s\n", query, dict[ i ] );
			return;
		}
	printf( "%s is unknown\n", query );
}

int main()
{

	scanf( "%d\n", &ds );
	for( int i = 0; i < ds; ++i )
		gets( dict[ i ] );
	scanf( "%d\n", &qs );
	for( int i = 0; i < qs; ++i )
		gets( query ), judge();
}
