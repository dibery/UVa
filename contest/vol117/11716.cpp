#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	char in[ 10001 ];
	int t, len, sq[ 101 ];
	for( int i = 0; i <= 100; ++i )
		sq[ i ] = i*i;
	scanf( "%d\n", &t );

	while( t-- )
	{
		gets( in );
		len = strlen( in );
		if( !binary_search( sq, sq+101, len ) )
			puts( "INVALID" );
		else
		{
			int root = sqrt( len ) + 1e-12;
			for( int i = 0; i < root; ++i )
				for( int j = 0; j < root; ++j )
					putchar( in[ j*root + i ] );
			puts( "" );
		}
	}

	return 0;
}
