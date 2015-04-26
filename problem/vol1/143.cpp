#include<bits/stdc++.h>
#define next ( i + 1 ) % 3
using namespace std;

inline int cross( int x1, int y1, int x2, int y2 ) { return x1*y2 - x2*y1; }

int main()
{
	double xt[ 3 ], yt[ 3 ];
	int x[ 3 ], y[ 3 ];

	while( true )
	{
		for( int i = 0; i < 3; ++i )
		{
			scanf( "%lf %lf", xt+i, yt+i );
			x[ i ] = ( xt[ i ] + 1e-12 ) * 100;
			y[ i ] = ( yt[ i ] + 1e-12 ) * 100;
		}
		if( all_of( x, x+3, [] ( int i ) { return i == 0; } ) && all_of( y, y+3, [] ( int i ) { return i == 0; } ) )
			break;

		int area = 0, xm = *min_element( x, x+3 ), xM = *max_element( x, x+3 ), ym = *min_element( y, y+3 ), yM = *max_element( y, y+3 );
		xM = min( xM, 9900 ), yM = min( yM, 9900 ), xm = max( xm, 100 ), ym = max( ym, 100 );
		for( int i = 0; i < 3; ++i )
			area += x[ i ] * y[ next ] - x[ next ] * y[ i ];
		if( area < 0 )
			reverse( x, x+3 ), reverse( y, y+3 );

		int ans = 0;
		for( int m = xm % 100 == 0? xm : xm + 100 - xm % 100; m <= xM; m += 100 )
			for( int n = ym % 100 == 0? ym : ym + 100 - ym % 100; n <= yM; n += 100 )
			{
				bool ok = true;
				for( int i = 0; i < 3 && ok; ++i )
					ok &= cross( x[ next ] - x[ i ], y[ next ] - y[ i ], m - x[ i ], n - y[ i ] ) >= 0;
				ans += ok;
			}
		printf( "%4d\n", ans );
	}
}