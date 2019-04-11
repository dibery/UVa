#include<cstdio>
#include<cmath>

struct fraction
{
	long long n, d;
	fraction( long long a = 1, long long b = 0 ): n( a ), d( b ) {}
	bool operator>( const fraction& f ) { return n * f.d > f.n * d; }
};

long long gcd( long long a, long long b )
{
	return a % b? gcd( b, a % b ) : b;
}

int main()
{
	for( long long L, n, d; scanf( "%lld %lld %lld", &L, &n, &d ) && L; )
	{
		fraction ans;
		for( int b = 1; b <= n; ++b )
			if( ans > fraction( ( d * b + L - 1 ) / L, b ) )
				ans = fraction( ( d * b + L - 1 ) / L, b );
		ans.n *= L;
		long long f = gcd( ans.n, ans.d );
		printf( "%lld/%lld\n", ans.n / f, ans.d / f );
	}
}
