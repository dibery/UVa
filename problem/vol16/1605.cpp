#include<cstdio>

int main()
{
	for( int n, t = 0; scanf( "%d", &n ) == 1; ++t )
	{
		char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

		printf( "2 %d %d\n", n, n );
		for( int i = 0; i < n; ++i, puts( "" ) )
			for( int j = 0; j < n; ++j )
				putchar( alpha[ i ] );
		puts( "" );
		for( int i = 0; i < n; ++i, puts( "" ) )
			for( int j = 0; j < n; ++j )
				putchar( alpha[ j ] );
	}
}
