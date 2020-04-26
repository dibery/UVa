#include<bits/stdc++.h>
using namespace std;

struct bit
{
	int *data, len;
	bit( int size )
	{
		len = ++size;
		data = new int[ len ];
		memset( data, 0, len * sizeof( int ) );
	}
	~bit()
	{
		delete[] data;
	}
	void add( int idx, int val = 1 )
	{
		for( ; idx < len; idx += idx & -idx )
			data[ idx ] += val;
	}
	int query( int idx )
	{
		int val = 0;
		for( ; idx; idx ^= idx & -idx )
			val += data[ idx ];
		return val;
	}
};

int main()
{
	int t, movie, act;

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &movie, &act ); )
	{
		int *pos = new int[ movie + act ];
		bit movie_pile( movie + act );
		int left = act;

		for( int i = 1; i <= movie; ++i )
			movie_pile.add( pos[ i ] = i + act );
		for( int target; act-- && scanf( "%d", &target ); )
		{
			movie_pile.add( pos[ target ], -1 );
			printf( "%d%c", movie_pile.query( pos[ target ] ), act? ' ' : '\n' );
			movie_pile.add( pos[ target ] = left-- );
		}
		delete[] pos;
	}
}
