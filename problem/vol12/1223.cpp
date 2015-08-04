#include<cstdio>
#include<cstring>
#include<algorithm>

int main()
{
	int t;

	for( scanf( "%d\n", &t ); t--; )
	{
		char s[ 5001 ] = { 0 };
		int len = strlen( gets( s ) ), ans = 0;

		for( int one = 0; one < len; ++one )
			for( int two = one+1; two < len; ++two )
				ans = std::max( ans, int( std::mismatch( s+one, s+len, s+two ).first - s - one ) );
		printf( "%d\n", ans );
	}
}
