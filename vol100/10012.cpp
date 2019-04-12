#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;

double pack( double r[], int size )
{
	double pos[ 8 ] = { 0 }, left = INFINITY, right = -INFINITY;
	for( int i = 1; i < size; ++i )
		for( int j = 0; j < i; ++j )
			pos[ i ] = max( pos[ i ], pos[ j ] + sqrt( pow( r[ i ] + r[ j ], 2 ) - pow( r[ i ] - r[ j ], 2 ) ) );
	for( int i = 0; i < size; ++i )
	{
		left = min( left, pos[ i ] - r[ i ] );
		right = max( right, pos[ i ] + r[ i ] );
	}
	return right - left;
}

int main()
{
	int t, s;
	double r[ 8 ];

	for( cin >> t; t-- && cin >> s; )
	{
		double ans = INFINITY;
		for( int i = 0; i < s; ++i )
			cin >> r[ i ];
		sort( r, r + s );
		do
			ans = min( ans, pack( r, s ) );
		while( next_permutation( r, r + s ) );
		cout << fixed << setprecision( 3 ) << ans << endl;
	}
}
