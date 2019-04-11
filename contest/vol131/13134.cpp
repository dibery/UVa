#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int scale, constant, mod, begin, query, size, cb, ce;
	while( ~scanf( "%d %d %d %d %d %d", &scale, &constant, &mod, &begin, &query, &size ) )
		if( size < 3000 )
		{
			int val[ 3000 ] = { 0, begin };
			for( int i = 2; i <= size; ++i )
				val[ i ] = ( scale * val[ i - 1 ] + constant ) % mod;
			sort( val + 1, val + size + 1 );
			for( int n; query-- && scanf( "%d", &n ); printf( "%d\n", val[ n ] ) );
		}
		else
		{
			int pos[ 1001 ] = { 0 }, f[ 1001 ] = { 0 }, cnt[ 1000 ] = { 0 };

			for( int val = begin, idx = 1; ; val = ( scale * val + constant ) % mod )
			{
				if( pos[ val ] )
				{
					ce = idx;
					cb = pos[ val ];
					break;
				}
				f[ idx ] = val;
				pos[ val ] = idx++;
			}

			for( int i = 1; i < cb; ++i )
				++cnt[ f[ i ] ];
			for( int i = cb; i < ce; ++i )
				cnt[ f[ i ] ] += ( size - cb + 1 ) / ( ce - cb );
			for( int i = ( size - cb + 1 ) / ( ce - cb ) * ( ce - cb ) + cb; i <= size; ++i )
				++cnt[ f[ ( i - cb ) % ( ce - cb ) + cb ] ];

			for( int q; query-- && scanf( "%d", &q ); )
			{
				int n = 0, sum = cnt[ 0 ];
				while( sum < q )
					sum += cnt[ ++n ];
				printf( "%d\n", n );
			}
		}
}
