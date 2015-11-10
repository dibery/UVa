#include<cstdio>

long long gcd( long long a, long long b ) { return b? gcd( b, a % b ) : a; }

int main()
{
	int t = 0;
	for( long long v1, d1, v2, d2; scanf( "%lld %lld %lld %lld", &v1, &d1, &v2, &d2 ) && v1; )
	{
		printf( "Case #%d: %s\nAvg. arrival time: ", ++t, d2 * v1 > d1 * v2?
				"You owe me a beer!" : "No beer for the captain." );
		long long down = v1 * v2, up = d2 * v1 + d1 * v2, f = gcd( down, up );
		down /= f;
		up /= f;
		if( down == 1 )
			if( up % 2 )
				printf( "%lld/2\n", up );
			else
				printf( "%lld\n", up / 2 );
		else
			if( up % 2 )
				printf( "%lld/%lld\n", up, down * 2 );
			else
				printf( "%lld/%lld\n", up / 2, down );
	}
}
