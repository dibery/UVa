#include<bits/stdc++.h>
using namespace std;

int main()
{
	int nx, ny;
	double width, x[ 1000 ], y[ 1000 ];

	while( scanf( "%d %d %lf", &nx, &ny, &width ) && nx )
	{
		bool ok = true;

		for( int i = 0; i < nx; ++i )
			scanf( "%lf", x+i );
		sort( x, x+nx );
		for( int i = 0; i < ny; ++i )
			scanf( "%lf", y+i );
		sort( y, y+ny );

		ok &= *x <= width / 2 && x[ nx-1 ] >= 75 - width / 2;
		ok &= *y <= width / 2 && y[ ny-1 ] >= 100 - width / 2;
		for( int i = 1; i < nx; ++i )
			ok &= x[ i ] - x[ i-1 ] <= width;
		for( int i = 1; i < ny; ++i )
			ok &= y[ i ] - y[ i-1 ] <= width;

		puts( ok? "YES" : "NO" );
	}
}
