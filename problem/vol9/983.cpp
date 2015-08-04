#include<cstdio>
#include<cstring>
int brd[ 1001 ][ 1001 ], size, blur, sum[ 1001 ][ 1001 ];
bool first = true;

int main()
{
	while( scanf( "%d %d", &size, &blur ) == 2 )
	{
		int S = 0;
		if( !first )
			puts( "" ), memset( sum, 0, sizeof( sum ) );
		first = false;
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%d", brd[ i ]+j );
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				sum[ i ][ j ] = j == 0? brd[ i ][ j ] : sum[ i ][ j-1 ] + brd[ i ][ j ];
		for( int i = 1; i < size; ++i )
			for( int j = 0; j < size; ++j )
				sum[ i ][ j ] += sum[ i-1 ][ j ];
		for( int i = blur-1; i < size; ++i )
			for( int j = blur-1; j < size; ++j )
			{
				int out = sum[ i ][ j ];
				if( i != blur-1 )
					out -= sum[ i-blur ][ j ];
				if( j != blur-1 )
					out -= sum[ i ][ j-blur ];
				if( i != blur-1 && j != blur-1 )
					out += sum[ i-blur ][ j-blur ];
				S += out;
				printf( "%d\n", out );
			}
		printf( "%d\n", S );
	}
}
