#include<cstdio>
#include<cmath>

int main()
{
	long long int x, y, t;
	scanf( "%lld", &t );

	while( t-- )
	{
		scanf( "%lld %lld", &x, &y ); 
		long long int dist = y-x, tmp = ceil( ( sqrt( dist*4 + 1 ) - 1 ) / 2 );
		if( tmp * tmp < dist && tmp * tmp + tmp >= dist || !tmp )
			printf( "%lld\n", tmp*2 );
		else
			printf( "%lld\n", tmp*2 - 1 );
	}

	return 0;
}
