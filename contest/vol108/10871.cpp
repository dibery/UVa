#include<cstdio>
bool notprime[ 100000001 ], vis[ 100000001 ];

bool isp( int n )
{
	if( vis[ n ] )
		return !notprime[ n ];
	vis[ n ] = true;
	if( n % 2 == 0 && n > 2 )
		return !( notprime[ n ] = true );
	for( int i = 3; i*i <= n; i += 2 )
		if( n % i == 0 )
			return !( notprime[ n ] = true );
	return true;
}

int main()
{
	int t, size, n[ 10000 ], sum[ 10000 ] = { 0 };

	for( scanf( "%d", &t ); t--; )
	{
		int begin = -1, end = -1;

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d", n+i );
		sum[ 1 ] = *n;
		for( int i = 1; i <= size; ++i )
			sum[ i ] = sum[ i-1 ] + n[ i-1 ];

		for( int b = 0; b < size; ++b )
			for( int e = b+2; e <= size && ( end == -1 || e-b < end-begin ); ++e )
				if( isp( sum[ e ] - sum[ b ] ) )
					begin = b, end = e;

		if( begin == -1 )
			puts( "This sequence is anti-primed." );
		else
			for( printf( "Shortest primed subsequence is length %d: ", end-begin ); begin < end; ++begin )
				printf( "%d%c", n[ begin ], begin == end-1? '\n' : ' ' );
	}
}
