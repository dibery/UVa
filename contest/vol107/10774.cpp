#include<iostream>
using namespace std;

int main()
{
	int joseph[ 30001 ] = { 0 }, t, n, r, T = 0;

	for( int i = 2; i < 30001; ++i )
		joseph[ i ] = ( 2 + joseph[ i - 1 ] ) % i;
	for( auto& i: joseph )
		++i;

	for( cin >> t; t-- && cin >> n; printf( "Case %d: %d %d\n", ++T, r, n ) )
		for( r = 0; joseph[ n ] != n; ++r )
			n = joseph[ n ];
}
