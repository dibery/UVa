#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

int main()
{
	int t, len;
	char in[ 20 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		long long sum = 0;

		for( int i = 0, len = strlen( gets( in ) ); i < len; ++i )
			sum += pow( in[ i ] - '0', len );

		puts( sum == atoi( in )? "Armstrong" : "Not Armstrong" );
	}
}
