#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, D, V;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d", &D, &V );
		printf( "Case %d: %.3f\n", n, sqrt( V * 282.0 / 7 * 8 * 3 / 2 / D / M_PI ) * 2 );
	}
}
