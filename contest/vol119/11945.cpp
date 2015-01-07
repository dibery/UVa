#include<cstdio>
#include<cstring>

int main()
{
	int t;
	char s[ 20 ];

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		double val = 0;
		for( double i = 0, j; i < 12; ++i )
			scanf( "%lf", &j ), val += j;

		sprintf( s, "%.2f", val / 12 );
		printf( "%d $", n );

		int len = strchr( s, '.' ) - s;
		for( int i = 0; i < len; ++i )
			printf( "%s%c", ( len - i ) % 3 == 0 && i != len-1 && i? "," : "", s[ i ] );
		puts( s+len );
	}
}
