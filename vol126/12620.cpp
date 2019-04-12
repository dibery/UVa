#include<cstdio>
inline long long int up( long long int n )
{
	if( n % 300 == 0 )
		return n;
	else
		return n - n % 300 + 300;
}
inline long long int down( long long int n )
{
	if( n % 300 == 0 )
		return n;
	else
		return n - n % 300;
}

int main()
{
	long long int t, begin, end, fib[ 301 ] = { 0, 1, 1 }, sum = 2, from, to;
	for( int i = 3; i <= 300; ++i )
		fib[ i ] = ( fib[ i-1 ] + fib[ i-2 ] ) % 100, sum += fib[ i ];
	scanf( "%lld", &t );

	while( t-- )
	{
		long long int ans = 0;
		scanf( "%lld %lld", &begin, &end );
		from = up( begin );
		to = down( end );
		if( from > to )
		{
			for( int i = begin % 300; i <= end % 300; ++i )
				ans += fib[ i ];
			printf( "%lld\n", ans );
			continue;
		}
		ans = ( to - from ) / 300 * sum;
		if( begin % 300 )
			for( int i = begin % 300; i < 300; ++i )
				ans += fib[ i ];
		for( int i = 1; i <= end % 300; ++i )
			ans += fib[ i ];
		printf( "%lld\n", ans );
	}

	return 0;
}
