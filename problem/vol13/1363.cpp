#include<cstdio>

long long int sigma( long long int a0, long long int n, long long int d ) { return ( a0 + a0+d*(n-1) ) * n / 2; }

int main()
{
	long long int n, k;

	while( scanf( "%lld %lld", &n, &k ) == 2 )
	{
		long long int ans = n > k? ( n-k ) * k : 0;
		if( n > k )
			n = k;
		for( int i = 1; i*i < k; ++i )
		{
			int begin = k/i, end = k/(i+1);
			if( end >= n )
				continue;
			if( begin > n )
				begin = n;
			ans += sigma( k % begin, begin - end, i );
		}
		for( int i = 1; i*i+i <= k && i <= n; ++i )
			ans += k % i;
		printf( "%lld\n", ans );
	}
}
