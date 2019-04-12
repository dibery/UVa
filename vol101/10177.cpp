#include<cstdio>

int main()
{
	long long int n, s2, s3, s4, r2, r3, r4;

	while( scanf( "%lld", &n ) == 1 )
	{
		long long int c = n * (n+1) / 2;
		s2 = n * (n+1) * (n*2+1) / 6;
		r2 = c * c - s2;
		s3 = c * c;
		r3 = c * c * c - s3;
		s4 = c * (n*2+1) * (n*n*3+n*3-1) / 15;
		r4 = c * c * c * c - s4;
		printf( "%lld %lld %lld %lld %lld %lld\n", s2, r2, s3, r3, s4, r4 );
	}
}
