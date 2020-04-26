#include<bits/stdc++.h>
using namespace std;

const int N = 200001, BATCH = 2000;
int size;

struct bit
{
	int *data, len;
	bit() { memset( data = new int[ len = size + 1 ], 0, ( size + 1 ) * sizeof( int ) ); }
	~bit() { delete[] data; }
	void add( int idx, int val = 1 )
	{
		for( ; idx < len; idx += idx & -idx )
			data[ idx ] += val;
	}
	int query( int idx, int val = 0 )
	{
		for( ; idx; idx ^= idx & -idx )
			val += data[ idx ];
		return val;
	}
};

int main()
{
	for( int rm, num[ N ]; ~scanf( "%d %d", &size, &rm ); )
	{
		long long inv = 0;
		int pos[ N ] = { 0 };
		bool gone[ N ] = { false };
		bit digits, segment[ size / BATCH + 1 ];

		for( int i = 1; i <= size && scanf( "%d", num + i ); ++i )
		{
			digits.add( num[ i ] );
			pos[ num[ i ] ] = i;
			inv += i - 1 - digits.query( num[ i ] - 1 );
			segment[ ( i - 1 ) / BATCH ].add( num[ i ] );
		}
		for( int target; rm-- && scanf( "%d", &target ); )
		{
			printf( "%lld\n", inv );
			gone[ pos[ target ] ] = true;
			int here_batch = ( pos[ target ] - 1 ) / BATCH;
			for( int i = here_batch * BATCH + 1, j = i + BATCH; i < j && i <= size; ++i )
				if( !gone[ i ] )
					inv -= i < pos[ target ] && num[ i ] > target || i > pos[ target ] && num[ i ] < target;
			segment[ here_batch ].add( target, -1 );
			for( int i = 0; i < here_batch; ++i )
					inv -= segment[ i ].query( size ) - segment[ i ].query( target );
			for( int i = here_batch + 1; i < ( size + BATCH - 1 ) / BATCH; ++i )
					inv -= segment[ i ].query( target );
		}
	}
}
