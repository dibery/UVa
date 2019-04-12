#include<cstdio>
#include<cstring>
#include<queue>

inline int stoi( char* s ) { return ( s[ 0 ] - 'A' ) * 26 + s[ 1 ] - 'A'; }
inline char* itos( int n ) { static char s[ 3 ] = { 0 }; s[ 0 ] = n / 26 + 'A'; s[ 1 ] = n % 26 + 'A'; return s; }
void path( int prev[], int n )
{
	char a[ 3 ], b[ 3 ];
	if( prev[ n ] != n )
		path( prev, prev[ n ] );
	else
		return;
	strcpy( a, itos( prev[ n ] ) );
	strcpy( b, itos( n ) );
	printf( "%s %s\n", a, b );
}

int main()
{
	for( int edge, first = 1; scanf( "%d", &edge ) == 1; )
	{
		bool adj[ 676 ][ 676 ] = { { false } };
		char from[ 3 ], to[ 3 ];
		int prev[ 676 ] = { 0 }, begin, end;

		if( first )
			first = 0;
		else
			puts( "" );

		for( int i = 0; i < edge; ++i )
		{
			scanf( "%s %s", from, to );
			adj[ stoi( from ) ][ stoi( to ) ] = adj[ stoi( to ) ][ stoi( from ) ] = true;
		}

		scanf( "%s %s", from, to );
		begin = stoi( from );
		end = stoi( to );
		std::queue<int> bfs;
		memset( prev, -1, sizeof( prev ) );
		prev[ begin ] = begin;

		for( bfs.push( begin ); !bfs.empty(); bfs.pop() )
			for( int i = 0; i < 676; ++i )
				if( adj[ bfs.front() ][ i ] && prev[ i ] == -1 )
					prev[ i ] = bfs.front(), bfs.push( i );
		if( prev[ end ] != -1 )
			path( prev, end );
		else
			puts( "No route" );
	}
}
