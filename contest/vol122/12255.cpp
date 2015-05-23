#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef pair<long long,long long> pii;

bool ok( pii pos[], int enemy, int stand, int has, long long dist )
{
	for( int man = 0, beat = 0; beat < enemy && man < has; ++man )
		for( long long L = INT_MIN, R = INT_MAX, dy; ; ++beat )
		{
			if( beat == enemy )
				return true;
			if( ( dy = pos[ beat ].y - stand ) > dist )
				return false;
			long long d = sqrt( dist * dist - dy * dy ), l = pos[ beat ].x - d, r = pos[ beat ].x + d;
			if( l > R )
				break;
			else
				L = max( L, l ), R = min( R, r );
		}

	return false;
}

int main()
{
	int t, river, enemy, me, dist;
	pii pos[ 10000 ];

	cin >> t;
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d %d %d %d", &river, &enemy, &me, &dist );
		for( int i = 0; i < enemy; ++i )
			scanf( "%lld %lld", &pos[ i ].x, &pos[ i ].y );
		sort( pos, pos + enemy );

		long long low = INT_MIN, high = river, mid;

		for( mid = ( low + high ) / 2; low < high; mid = floor( ( low + high ) / 2.0 ) )
			if( !ok( pos, enemy, mid, me, dist ) )
				low = mid+1;
			else
				high = mid;
		if( ok( pos, enemy, mid, me, dist ) )
			printf( "Case %d: %lld\n", n, river - mid );
		else
			printf( "Case %d: IMPOSSIBLE\n", n );
	}
}
