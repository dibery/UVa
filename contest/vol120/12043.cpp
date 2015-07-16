#include<bits/stdc++.h>
using namespace std;
#define N 100001
int prime[ 10000 ] = { 2 }, size = 1, num[ N ], sum[ N ];

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

int main()
{
	for( int i = 3; i < 100000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	fill( sum, sum + N, 1 );
	fill( num, num + N, 1 );
	for( int i = 2; i < N; ++i )
		for( int j = 0, n = i, t; j < size && prime[ j ] <= n; ++j )
			if( t = time( n, prime[ j ] ) )
			{
				num[ i ] *= t+1;
				sum[ i ] *= ( pow( prime[ j ], t+1 ) - 1 ) / ( prime[ j ] - 1 );
			}

	int t, a, b, k;

	for( scanf( "%d", &t ); t--; )
	{
		long long A = 0, B = 0;
		scanf( "%d %d %d", &a, &b, &k );
		for( a += ( k - a % k ) % k; a <= b; a += k )
			A += num[ a ], B += sum[ a ];
		printf( "%lld %lld\n", A, B );
	}
}
