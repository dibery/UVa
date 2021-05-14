#include<bits/stdc++.h>
using namespace std;

int move( list<int> child[], int ball[], int idx, int& ans )
{
	for( int c: child[ idx ] )
		ball[ idx ] += move( child, ball, c, ans );
	ans += abs( ball[ idx ] - 1 );
	return ball[ idx ] - 1;
}

int main()
{
	for( int size, ball[ 10000 ]; scanf( "%d", &size ) && size; )
	{
		list<int> child[ 10000 ];
		bool is_child[ 10000 ] = { false };
		int ans = 0;

		for( int i = 0, id, C; i < size && scanf( "%d", &id ); ++i )
		{
			scanf( "%d %d", ball + --id, &C );
			for( int c; C-- && scanf( "%d", &c ); )
				child[ id ].push_back( --c ), is_child[ c ] = true;
		}
		move( child, ball, find( is_child, is_child + size, false ) - is_child, ans );
		printf( "%d\n", ans );
	}
}
