#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,char> pic;

int size( char brd[ 55 ][ 55 ], int i, int j, char c )
{
	int ans = 1;

	brd[ i ][ j ] = '.';
	for( int m = i-1; m <= i+1; ++m )
		for( int n = j-1; n <= j+1; ++n )
			if( i != m ^ j != n && brd[ m ][ n ] == c )
				ans += size( brd, m, n, c );

	return ans;
}

int main()
{
	for( int h, w, t = 0; scanf( "%d %d", &h, &w ) && h; )
	{
		vector<pic> stat;
		char brd[ 55 ][ 55 ], cp[ 55 ][ 55 ];

		memset( brd, '.', sizeof( brd ) );
		for( int i = 1; i <= h; ++i )
			scanf( "%s", brd[ i ] + 1 ), brd[ i ][ w+1 ] = '.';
		memcpy( cp, brd, sizeof( brd ) );

		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( brd[ i ][ j ] != '.' )
					stat.push_back( pic( size( brd, i, j, brd[ i ][ j ] ), cp[ i ][ j ] ) );
		sort( stat.begin(), stat.end(), [] ( pic a, pic b ) { return a.first != b.first? a.first > b.first : a.second < b.second; } );

		printf( "Problem %d:\n", ++t );
		for( vector<pic>::iterator i = stat.begin(); i != stat.end(); ++i )
			printf( "%c %d\n", i->second, i->first );
	}
}
