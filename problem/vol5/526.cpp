#include<cstdio>
#include<cstring>
#include<list>
#include<algorithm>
using namespace std;
enum way { none, add, del, rep };
char method[][ 8 ] = { "", "Insert", "Delete", "Replace" };
class dp
{
public:
	int cost;
	way dir;
	dp() { cost = 0; dir = none; }
	void operator= ( int n ) { cost = n; }
};
class trans
{
public:
	int i, j, pos;
	char letter;
	way method;
	trans( int h = 0, int w = 0, way d = none, int p = 0, char c = 0 ) { i = h; j = w; letter = c; method = d; pos = p; }
};

int main()
{
	char a[ 82 ], b[ 82 ];
	bool first = true;

	while( gets( a+1 ) && gets( b+1 ) )
	{
		if( !first )
			puts( "" );
		first = false;
		list<trans>process;
		int la = strlen( a+1 ), lb = strlen( b+1 ), h = la, w = lb, id = 0, offset = 0;
		dp cell[ la + 1 ][ lb + 1 ];

		for( int i = 0; i <= la; ++i )
			cell[ i ][ 0 ] = i, cell[ i ][ 0 ].dir = del;
		for( int i = 1; i <= lb; ++i )
			cell[ 0 ][ i ] = i, cell[ 0 ][ i ].dir = add;
		for( int i = 1; i <= la; ++i )
			for( int j = 1; j <= lb; ++j )
				if( a[ i ] == b[ j ] )
				{
					cell[ i ][ j ] = cell[ i-1 ][ j-1 ];
					cell[ i ][ j ].dir = none;
				}
				else
				{
					cell[ i ][ j ].cost = min( cell[ i-1 ][ j-1 ].cost, min( cell[ i-1 ][ j ].cost, cell[ i ][ j-1 ].cost ) ) + 1;
					if( cell[ i ][ j ].cost == cell[ i-1 ][ j-1 ].cost + 1 )
						cell[ i ][ j ].dir = rep;
					else if( cell[ i ][ j ].cost == cell[ i-1 ][ j ].cost + 1 )
						cell[ i ][ j ].dir = del;
					else
						cell[ i ][ j ].dir = add;
				}

		printf( "%d\n", cell[ la ][ lb ].cost );
		while( h || w )
		{//printf("At %d %d: %s Cost: %d\n", h, w, method[ cell[ h ][ w ].dir ], cell[ h ][ w ].cost );
			if( cell[ h ][ w ].dir == add )
			{
				process.push_front( trans( h, w, add, h+1, b[ w ] ) );
				--w;
			}
			else if( cell[ h ][ w ].dir == del )
			{
				process.push_front( trans( h, w, del, h ) );
				--h;
			}
			else if( cell[ h ][ w ].dir == rep )
			{
				process.push_front( trans( h, w, rep, h, b[ w ] ) );
				--h;
				--w;
			}
			else
				--h, --w;
		}
		for( list<trans>::iterator it = process.begin(); it != process.end(); ++it )
		{
			if( it->method == add )
				it->pos += offset++;
			else if( it->method == del )
				it->pos += offset--;
			else
				it->pos += offset;
		}
		for( list<trans>::iterator it = process.begin(); it != process.end(); ++it )
		{
			if( it->method != del )
				printf( "%d %s %d,%c\n", ++id, method[ it->method ], it->pos, it->letter );
			else
				printf( "%d %s %d\n", ++id, method[ it->method ], it->pos );
		}
	}
	return 0;
}
