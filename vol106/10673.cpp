#include<cstdio>
void gcd( int a, int b, int& x, int& y )
{
	if( !b )
		x = 1, y = 0;
	else
		gcd( b, a%b, y, x ), y -= a / b * x;
}

int main()
{
	int x, k, a, b, t;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &x, &k );
		if( x % k == 0 )
			printf( "0 %d\n", k );
		else
		{
			gcd( x/k, (x+k-1)/k, a, b );
			printf( "%lld %lld\n", (long long int)a*x, (long long int)b*x );
		}
	}
}
