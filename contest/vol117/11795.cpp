#include<cstdio>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;

long long int cnt[ 65536 ] = { 1 };
bool me[ 16 ], defeat[ 16 ][ 16 ], vis[ 65536 ] = { false };
int size;

bool ok( int now, int done )
{
	for( int i = 0; i < size; ++i )
		if( done & 1 << i && defeat[ i ][ now ] )
			return true;
	return false;
}

int main()
{
	int t;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d\n", &size );
		for( int i = 0; i < size; ++i )
			me[ i ] = getchar() == '1';
		getchar();
		for( int i = 0; i < size; ++i, getchar() )
			for( int j = 0; j < size; ++j )
				defeat[ i ][ j ] = getchar() == '1';
		fill( vis, vis+65536, false );
		fill( cnt+1, cnt+65536, 0 );

		queue<int> calc;
		for( calc.push( 0 ); !calc.empty(); calc.pop() )
		{
			if( vis[ calc.front() ] )
				continue;
			vis[ calc.front() ] = true;
			for( int i = 0, N = calc.front(); i < size; ++i )
				if( ( me[ i ] || ok( i, N ) ) && ( N & 1 << i ) == 0 )
				{
					cnt[ N | 1 << i ] += cnt[ N ];
					calc.push( N | 1 << i );
				}
		}
		printf( "Case %d: %lld\n", n, cnt[ ( 1 << size ) - 1 ] );
	}
}
