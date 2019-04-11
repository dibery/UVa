#include<cstdio>
#include<algorithm>
int gcd( int a, int b ) { return a % b? gcd( b, a%b ) : b; }
void gcd( int a, int b, long long int& x, long long int& y )
{
	if( !b )
		x = 1, y = 0;
	else
		gcd( b, a%b, y, x ), y -= a / b * x;
}

int main()
{
	long long int f, x, y, n, c1, c2, n1, n2, q1, q2;

	while( scanf( "%lld", &n ) && n )
	{
		scanf( "%lld %lld %lld %lld", &c1, &n1, &c2, &n2 );
		bool swap = false, ok = true;
		f = gcd( n1, n2 );
		if( n % f )
			ok = false;
		else
			n /= f, n1 /= f, n2 /= f;
		if( c2 * n1 < c1 * n2 )
			std::swap( c1, c2 ), std::swap( n1, n2 ), swap = true;
		gcd( n2, n1, x, y );
		q2 = (n1+x) * n % n1;
		q1 = ( n - q2*n2 ) / n1;
		ok &= n1*q1 + n2*q2 == n && q1 >= 0 && q2 >= 0;
		if( swap )
			std::swap( q1, q2 );
		printf( ok? "%lld %lld\n" : "failed\n", q1, q2 );
	}
}
