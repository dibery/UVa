#include<bits/stdc++.h>
using namespace std;

bool ok( double pos[], int size, double time, double jump )
{
	double calc[ 10000 ] = { 0 };

	for( int i = 0; i < size-1; ++i )
		calc[ i ] = pos[ i+1 ] - pos[ i ];
	*calc -= time;
	if( size >= 2 )
		calc[ size-2 ] -= time;
	for( int i = 0; i < size-2; ++i )
		if( calc[ i ] <= jump + DBL_EPSILON )
		{
			calc[ i+1 ] -= min( jump - calc[ i ], time );
			calc[ i ] += min( jump - calc[ i ], time );
		}
		else if( calc[ i ] <= jump + time + DBL_EPSILON )
		{
			calc[ i+1 ] += min( time, calc[ i ] - jump );
			calc[ i ] -= min( time, calc[ i ] - jump );
		}
		else
			return false;
	if( size > 1 && calc[ size-2 ] - jump > DBL_EPSILON )
		return false;
	return true;
}

int main()
{
	for( int size, t = 0; scanf( "%d", &size ) && size; )
	{
		double jump, pos[ 10000 ] = { 0 };

		for( int i = 0; i < size; ++i )
			scanf( "%lf", pos + i );
		scanf( "%lf", &jump );
		sort( pos, pos + size );

		double low = 0, high = pos[ size-1 ], mid;

		for( mid = high / 2; high - mid > 1e-4; mid = ( high + low ) / 2 )
			if( ok( pos, size, mid, jump ) )
				high = mid;
			else
				low = mid;

		printf( "Case %d: %.3f\n", ++t, mid );
	}
}
