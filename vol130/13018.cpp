#include<cstdio>
#include<algorithm>

int main()
{
	bool first = true;

	for( int m, n; scanf( "%d %d", &m, &n ) == 2; )
	{
		if( first )
			first = false;
		else
			puts( "" );

		for( int i = std::min( m, n ) + 1; i <= std::max( m, n ) + 1; ++i )
			printf( "%d\n", i );
	}
}
