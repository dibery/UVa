#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t, money, item, len[ 20 ], cost[ 20 ][ 20 ] = { { 0 } };

	for( cin >> t; t-- && cin >> money >> item; )
	{
		int ans[ 20 ][ 201 ] = { { 0 } }, base = 0;

		for( int i = 0; i < item && cin >> len[ i ]; ++i )
		{
			for( int j = 0; j < len[ i ]; ++j )
				cin >> cost[ i ][ j ];
			sort( cost[ i ], cost[ i ] + len[ i ] );
			base += *cost[ i ];
			len[ i ] = upper_bound( cost[ i ], cost[ i ] + len[ i ], money ) - cost[ i ];
		}

		for( int i = 0; i < len[ 0 ]; ++i )
			for( int j = cost[ 0 ][ i ]; j < ( i == len[ 0 ] - 1? money + 1: cost[ 0 ][ i + 1 ] ); ++j )
				ans[ 0 ][ j ] = cost[ 0 ][ i ];
		for( int i = 1; i < item; ++i )
			for( int m = 1; m <= money; ++m )
				for( int j = 0; j < len[ i ]; ++j )
					if( m >= cost[ i ][ j ] && ans[ i - 1 ][ m - cost[ i ][ j ] ] )
						ans[ i ][ m ] = max( ans[ i ][ m ], cost[ i ][ j ] + ans[ i - 1 ][ m - cost[ i ][ j ] ] );
		if( base <= money )
			cout << ans[ item - 1 ][ money ] << endl;
		else
			cout << "no solution\n";
	}
}
