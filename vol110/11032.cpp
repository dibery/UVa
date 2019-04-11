#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int size = 10000000;

int sod( int n )
{
	int ans = 0;
	while( n )
		ans += n % 10, n /= 10;
	return ans;
}
int calc[ size+1 ], all[ size+1 ];
bool reachable[ size+1 ];

int main()
{
	int t, a, b;
	int cnt = 0;
	char in[ 50 ];
	for( int i = 1; i <= size; ++i )
	{
		int tmp = i + sod(i);
		if( !reachable[ tmp ] )
			calc[ tmp ] = i;
		reachable[ tmp ] = true;
	}
	for( int i = 1; i <= size; ++i )
		all[ i ] = all[ i-1 ] + reachable[ i ];

	scanf( "%d%*c", &t );

	for( int n = 1; n <= t; ++n )
	{
		gets( in );
		if( strchr( in, ' ' ) == NULL )
			sscanf( in, "%d", &a ), printf( "Case %d: %d\n", n, reachable[ a ]? calc[ a ] : -1 );
		else
			sscanf( in, "%d %d", &a, &b ), printf( "Case %d: %d\n", n, b - a + 1 - all[ b ] + all[ a-1 ] );
	}
}