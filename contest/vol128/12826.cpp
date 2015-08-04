#include<bits/stdc++.h>

int main()
{
	int r1, r2, r3, c1, c2, c3;

	for( int t = 1; scanf( "%d %d %d %d %d %d", &r1, &c1, &r2, &c2, &r3, &c3 ) == 6; ++t )
		printf( "Case %d: %d\n", t, std::max( abs( r2-r1 ), abs( c2-c1 ) ) + ( ( r3+c3 == r1+c1 && r2+c2 == r1+c1 || r3-c3 == r1-c1 && r2-c2 == r1-c1 ) && r1>=r3 != r2>=r3 ) );
}
