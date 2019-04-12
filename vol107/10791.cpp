#include<cstdio>

int prime[ 10000 ] = { 2 }, size = 1, n, t;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

unsigned int div( int& n, int d )
{
	unsigned int s = 1;
	while( n % d == 0 )
		n /= d, s *= d;
	return s;
}

int main()
{
	for( int i = 3; i < 46340; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	while( scanf( "%d", &n ) && n )
	{
		unsigned int ans = n == 1? 1 : 0, mark = 0;
		for( int i = 0; i < size; ++i )
			if( n % prime[ i ] == 0 )
				ans += div( n, prime[ i ] ), ++mark;
		if( n != 1 )
			ans += n;
		printf( "Case %d: %u\n", ++t, ans + ( mark <= 1 ) );
	}
}
