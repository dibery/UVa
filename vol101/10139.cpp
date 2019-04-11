#include<cstdio>

int prime[ 40000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int time( int& n, int div )
{
	int t = 0;
	while( n % div == 0 )
		n /= div, ++t;
	return t;
}

int calc( int f, int div )
{
	int ans = 0;
	for( int i = f / div; i; i /= div )
		ans += i;
	return ans;
}

int main()
{
	int fact, div, cp;

	for( int i = 3; i < 46340; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	while( scanf( "%d %d", &fact, &div ) == 2 )
	{
		bool ok = true;
		cp = div;
		for( int i = 0; i < size && ok && div != 1; ++i )
			if( time( div, prime[ i ] ) > calc( fact, prime[ i ] ) )
				ok = false;
		if( div != 1 && fact < div )
			ok = false;
		if( ok )
			printf( "%d divides %d!\n", cp, fact );
		else
			printf( "%d does not divide %d!\n", cp, fact );
	}
}
