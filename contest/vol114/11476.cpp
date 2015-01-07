#include<cstdio>

bool notprime[ 100000000 ];
long long int prime[ 10000000 ], size = 1;

void calc( long long int& n, long long int f, bool& first )
{
	int t = 0;

	while( n % f == 0 )
		n /= f, ++t;
	printf( first? "" : " * " );
	first = false;
	if( t > 1 )
		printf( "%lld^%d", f, t );
	else
		printf( "%lld", f );
}

int main()
{
	int t;
	long long int n;
	notprime[ 0 ] = notprime[ 1 ] = true;
	*prime = 2;

	for( int i = 3; i < 1e4; i += 2 )
		if( !notprime[ i ] )
			for( int j = i*i; j < 1e8; j += i << 1 )
				notprime[ j ] = true;
	for( int i = 3; i < 1e8; i += 2 )
		if( !notprime[ i ] )
			prime[ size++ ] = i;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%lld", &n );
		bool first = true;
		printf( "%lld = ", n );
		for( int i = 0; i < size && prime[ i ] * prime[ i ] <= n; ++i )
			if( n % prime[ i ] == 0 )
				calc( n, prime[ i ], first );
		if( n > 1 )
			calc( n, n, first );
		puts( "" );
	}
}
