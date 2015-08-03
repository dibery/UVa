#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int match( char* s, char* p )
{
	int fail[ 80 ] = { -1 }, time = 0, ls = strlen( s ), lp = strlen( p );

	if( lp > ls )
		return 0;
	for( size_t i = 1; i < lp; ++i )
	{
		int j = fail[ i-1 ];
		while( j >= 0 && p[ j+1 ] != p[ i ] )
			j = fail[ j ];
		fail[ i ] = j += p[ j+1 ] == p[ i ];
	}
	for( int i = 0, j = -1; i < ls; ++i )
	{
		while( j >= 0 && p[ j+1 ] != s[ i ] )
			j = fail[ j ];
		if( ( j += p[ j+1 ] == s[ i ] ) == lp-1 )
			++time, j = fail[ j ];
	}
	return time;
}

int main()
{
	//freopen( ".test", "r", stdin );
	for( int size; scanf( "%d\n", &size ) && size; )
	{
		char pattern[ 150 ][ 71 ] = { { 0 } }, s[ 1000000 ];
		int time[ 200 ] = { 0 }, M;

		for( int i = 0; i < size; ++i )
			gets( pattern[ i ] );
		gets( s );
		for( int i = 0; i < size; ++i )
			time[ i ] = match( s, pattern[ i ] );

		M = *max_element( time, time + size );
		cout << M << endl;
		for( int i = 0; i < size; ++i )
			if( time[ i ] == M )
				puts( pattern[ i ] );
	}
}
