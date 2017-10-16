#include<bits/stdc++.h>
using namespace std;

bool reach[ 51 ][ 10001 ], tmp[ 51 ][ 10001 ];

int main()
{
	for( int p, q, x[ 100 ]; cin >> p >> q; )
	{
		if( p > q )
			swap( p, q );
		for( int i = 0; i < p + q; ++i )
			cin >> x[ i ];

		int sum = accumulate( x, x + p + q, 0 );

		memset( reach, false, sizeof( reach ) );
		reach[ 0 ][ 5000 ] = true;
		for( int i = 0; i < p + q; ++i )
		{
			memset( tmp, false, sizeof( tmp ) );
			for( int j = 1; j <= min( i + 1, p ); ++j )
				for( int k = 0; k <= 10000; ++k )
					if( reach[ j - 1 ][ k ] )
						tmp[ j ][ k + x[ i ] ] = reach[ j - 1 ][ k ];
			for( int j = 1; j <= min( i + 1, p ); ++j )
				for( int k = 0; k <= 10000; ++k )
					reach[ j ][ k ] |= tmp[ j ][ k ];
		}

		int m = INT_MAX, M = INT_MIN;

		for( int i = 0; i <= 10000; ++i )
			if( reach[ p ][ i ] )
			{
				m = min( m, ( i - 5000 ) * ( sum - i + 5000 ) );
				M = max( M, ( i - 5000 ) * ( sum - i + 5000 ) );
			}
		cout << M << ' ' << m << endl;
	}
}
