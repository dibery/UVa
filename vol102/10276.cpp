#include<cstdio>
#include<cmath>
#include<ctime>
#include<algorithm>

bool issqr( int n )
{
	for( int i = 1; i*i <= n; ++i )
		if( n == i*i )
			return true;
	return false;
}

void hanoi( int runtime, int* peg, int total, int& M, int now = 1, int used = 0 )
{
	if( used > total || clock() - runtime > 0.01 * CLOCKS_PER_SEC )
		return;
	for( int i = 0; i <= used && i < total; ++i )
		if( i == used || issqr( peg[ i ] + now ) )
		{
			int tmp = peg[ i ];
			peg[ i ] = now;
			M = std::max( M, now );
			hanoi( runtime, peg, total, M, now+1, used + ( i == used ) );
			peg[ i ] = tmp;
		}
}

int main()
{
	int n, t;

	for( scanf( "%d", &t ); t--; )
	{
		int M = 0, stat[ 50 ] = { 0 };
		scanf( "%d", &n );
		hanoi( clock(), stat, n, M );
		printf( "%d\n", M );
	}
}
