#include<cstdio>

int main()
{
	for( int n; scanf( "%d", &n ) == 1; )
	{
		int pos = 2, size = 0, x = 0, y = n != 1, d = 0;

		while( pos + ( size += 6 ) <= n )
			pos += size, ++x, ++d;
		for( int i = 0; i < d && pos < n; ++i )
			++pos, --x, ++y;
		for( int i = 0; i <= d && pos < n; ++i )
			++pos, --x;
		for( int i = 0; i <= d && pos < n; ++i )
			++pos, --y;
		for( int i = 0; i <= d && pos < n; ++i )
			++pos, ++x, --y;
		for( int i = 0; i <= d && pos < n; ++i )
			++pos, ++x;
		for( int i = 0; i <= d && pos < n; ++i )
			++pos, ++y;

		printf( "%d %d\n", x, y );
	}
}
