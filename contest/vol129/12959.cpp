#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	for( int player, round, score[ 500 ], idx; scanf( "%d %d", &player, &round ) == 2; )
	{
		fill( score, score + player, idx = 0 );
		for( int i = 0, n; i < round; ++i )
			for( int j = 0; j < player; ++j )
				scanf( "%d", &n ), score[ j ] += n;
		for( int i = 0, M = -1; i < player; ++i )
			if( score[ i ] >= M )
				M = score[ i ], idx = i;
		printf( "%d\n", idx + 1 );
	}
}
