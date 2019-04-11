#include<cstdio>

int main()
{
	int t, n;

	for( scanf( "%d", &t ); t; --t )
	{
		long long int ans = 0;
		scanf( "%d", &n );
		for( int div = 1; div * div <= n && div <= 46340; ++div )
			ans += div * ( n / div - n / ( div + 1 ) );
		for( int div = 1; n / div > div; ++div )
			ans += n / div;
		printf( "%lld\n", ans );
	}
}
