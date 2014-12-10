#include<cstdio>
#include<algorithm>
#define NOW stack[put]
using namespace std;

int gcd[ 101 ][ 101 ] = { { 0 } }, stack[ 30 ];

int GCD( int a, int b ) { return a % b? GCD( b, a % b ) : b; }

void find( int sum, int part, int put = 0 )
{
	if( put == part-1 && sum < stack[ put-1 ] && stack[ put-1 ] != 1 )
		return;
	if( put == part )
		for( int i = 0; i < put; ++i )
			printf( "%d%c", stack[ i ], i == put-1? '\n' : ' ' );
	else
		for( NOW = put? put == part-1? sum : stack[ put-1 ] : 1; NOW <= sum; ++NOW )
			if( all_of( stack, stack+put, [put]( int n ){ return gcd[ n ][ NOW ] == 1; } ) )
				find( sum-NOW, part, put+1 );
}

int main()
{
	int t, sum, part;

	for( int i = 1; i <= 100; ++i )
		for( int j = i; j <= 100; ++j )
			gcd[ i ][ j ] = gcd[ j ][ i ] = GCD( i, j );

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &sum, &part );
		printf( "Case %d:\n", n );
		if( part > 1 )
			find( sum, part );
		else
			printf( "%d\n", sum );
	}
}
