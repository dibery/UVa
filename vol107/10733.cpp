#include<cstdio>
long long int C( long long int m, long long int n )
{
	long long int ans = 1;
	for( long long int i = 1; i <= n; ++i )
		ans *= m - i + 1, ans /= i;
	return ans;
}

int main()
{
	long long int n, base[ 7 ] = { 0, 1, 8, 30, 68, 75, 30 };

	while( scanf( "%lld", &n ) && n )
	{
		long long int ans = 0;
		for( long long int i = 1; i <= 6 && i <= n; ++i )
			ans += C( n, i ) * base[ i ];
		printf( "%lld\n", ans );
	}

	return 0;
}
