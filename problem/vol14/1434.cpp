#include<cstdio>

const int N = 3000009;
bool notprime[ N ] = { true, true };
int sum[ N / 3 ], t, n;

int main()
{
	for( int i = 4; i < N; i += 2 )
		notprime[ i ] = true;
	for( int i = 3; i * i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j <= N; j += 2 * i )
				notprime[ j ] = true;
	for( int i = 1; i < N / 3; ++i )
		sum[ i ] = sum[ i - 1 ] + !notprime[ 3 * i + 7 ];
	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); )
		printf( "%d\n", sum[ n ] );
}
