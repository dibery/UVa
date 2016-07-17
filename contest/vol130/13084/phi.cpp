#include<bits/stdc++.h>
using namespace std;

int GCD[ 5005 ][ 5005 ];

int gcd( int a, int b ) { return a % b? GCD[ b ][ a % b ] : b; }

struct frac
{
	int up, down;
	frac( int u = 0, int d = 0 ) : up( u ), down( d ) {}
	bool operator< ( const frac& f ) const { return up * f.down < down * f.up; }
};

int main()
{
	vector<frac> v;
	v.reserve( 7610000 );

	for( int i = 1; i <= 5001; ++i )
		for( int j = i; j <= 5001; ++j )
		{
			GCD[ j ][ i ] = GCD[ i ][ j ] = gcd( j, i );
			if( GCD[ i ][ j ] == 1 )
				v.push_back( frac( i, j ) );
		}
	sort( v.begin(), v.end() );
	cout << v.size();
}
