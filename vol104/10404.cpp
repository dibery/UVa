#include<cstdio>

int main()
{
	for( int stone, size, take[ 10 ]; scanf( "%d %d", &stone, &size ) == 2; )
	{
		for( int i = 0; i < size; ++i )
			scanf( "%d", take + i );
		bool win[ 1000001 ] = { false };
		for( int i = 1; i <= stone; ++i )
			for( int j = 0; j < size && !win[ i ]; ++j )
				if( take[ j ] <= i && !win[ i - take[ j ] ] )
					win[ i ] = true;
		puts( win[ stone ]? "Stan wins" : "Ollie wins" );
	}
}
