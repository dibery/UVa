#include<cstdio>
#include<algorithm>
using namespace std;

bool black( int n ) { return n < 128; }

int main()
{
	for( int t, cell[ 5 ]; scanf( "%d", &t ) && t; )
		while( t-- )
		{
			for( int i = 0; i < 5; ++i )
				scanf( "%d", cell + i );
			if( count_if( cell, cell + 5, black ) == 1 )
				printf( "%c\n", 'A' + find_if( cell, cell + 5, black ) - cell );
			else
				puts( "*" );
		}
}
