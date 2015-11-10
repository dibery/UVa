#include<cstdio>

char dict[ 100 ][ 300 ];
int size, rule, seq[ 256 ];

void out( char* format, int dep = 0 )
{
	if( format[ dep ] )
		for( int i = 0; i < ( format[ dep ] == '#'? size : 10 ); ++i )
			seq[ dep ] = i, out( format, dep + 1 );
	else
	{
		for( int i = 0; format[ i ]; ++i )
			if( format[ i ] == '#' )
				printf( dict[ seq[ i ] ] );
			else
				printf( "%d", seq[ i ] );
		puts( "" );
	}
}

int main()
{
	for( char s[ 300 ]; scanf( "%d\n", &size ) == 1; )
	{
		puts( "--" );
		for( int i = 0; i < size; ++i )
			gets( dict[ i ] );
		for( scanf( "%d\n", &rule ); rule--; )
			out( gets( s ) );
	}
}
