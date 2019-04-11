#include<cstdio>
#include<algorithm>
int array[ 100000 ], tmp, index = 0, max = 0;
char delim;
bool in;

int main()
{
	while( in = scanf( "%d%c", &tmp, &delim ) == 2 )
		if( !in || delim == '\n' )
		{
			array[ index ] = tmp;
			for( int i = 0, now = 0; i <= index; ++i )
			{
				max = std::max( max, now += array[ i ] );
				now = std::max( 0, now );
			}
			printf( "%d\n", max );
			max = index = 0;
		}
		else
			array[ index++ ] = tmp;

	return 0;
}
