#include<cstdio>
#include<cstring>
using namespace std;
struct cell 
{ 
	int number; 
	bool content; 
};
int solution = 0;
cell sudoku[ 9 ][ 9 ];
bool legal( int x, int y, int value );
void fill( int, int );

int main()
{
	int T = 0, done = 0;

	while( scanf( "%d", &sudoku[ 0 ][ 0 ].number ) == 1 )
	{
		bool leave = false;
		for( int i = 0; i < 9; ++i )
			for( int j = 0; j < 9; ++j )
			{
				if( i | j )
					scanf( "%d", &sudoku[ i ][ j ].number );
				sudoku[ i ][ j ].content = sudoku[ i ][ j ].number;
				if( sudoku[ i ][ j ].content )
					++done;
				if( sudoku[ i ][ j ].content && !leave && !legal( i, j, sudoku[ i ][ j ].number ) )
					leave = true;
			}
		if( leave )
			printf( "Case %d: Illegal.\n", ++T );
		else
		{
			fill( 0, done );
			if( !solution )
				printf( "Case %d: Impossible.\n", ++T );
			else
				printf( "Case %d: %s.\n", ++T, solution == 1? "Unique" : "Ambiguous" );
		}
		memset( sudoku, done = solution = 0, sizeof( sudoku ) );
	}
	return 0;
}

void fill( int begin_cell, int  done )
{
	if( done == 81 )
	{
		++solution;
		return;
	}
	if( solution > 1 )
		return;
	if( !sudoku[ begin_cell / 9 ][ begin_cell % 9 ].content )
	{
		for( int k = 1; k <= 9; ++k )
			if( legal( begin_cell / 9, begin_cell % 9, k ) )
			{
				sudoku[ begin_cell / 9 ][ begin_cell % 9 ].number = k;
				fill( begin_cell+1, done+1 );
			}
		sudoku[ begin_cell / 9 ][ begin_cell % 9 ].number = 0;
	}
	else
		fill( begin_cell+1, done );
}

bool legal( int x, int y, int value )
{
	for( int i = 0; i < 9; ++i )
		if( i != x && value == sudoku[ i ][ y ].number )
			return false;
	for( int i = 0; i < 9; ++i )
		if( i != y && value == sudoku[ x ][ i ].number )
			return false;
	for( int i = (x / 3) * 3; i <= (x / 3) * 3 + 2; ++i )
		for( int j = (y / 3) * 3; j <= (y / 3) * 3 + 2; ++j )
			if( !( i == x && j == y ) && value == sudoku[ i ][ j ].number )
				return false;
	return true;
}
