#include<cstdio>
#include<vector>

int max( int a, int b ) { return a < b? b : a; }
int min( int a, int b ) { return a > b? b : a; }

struct seg
{
	seg( int data[], int LB, int UB, int (*Func)( int, int ) ) : lb( LB ), ub( UB ), func( Func )
	{
		if( UB - LB > 1 )
		{
			left = new seg( data, LB, ( LB + UB ) / 2, Func );
			right = new seg( data, ( LB + UB ) / 2, UB, Func );
			val = Func( left->val, right->val );
		}
		else
			val = data[ LB ], left = right = NULL;
	}
	void update( int idx, int n_val )
	{
		if( lb <= idx && idx < ub )
			if( ub - lb == 1 )
				val = n_val;
			else
			{
				left->update( idx, n_val );
				right->update( idx, n_val );
				val = func( left->val, right->val );
			}
	}
	int query( int LB, int UB )
	{
		if( LB == lb && UB == ub )
			return val;
		if( UB <= left->ub )
			return left->query( LB, UB );
		if( LB >= right->lb )
			return right->query( LB, UB );
		return func( left->query( LB, left->ub ), right->query( right->lb, UB ) );
	}
	int lb, ub, val;
	seg *left, *right;
	int ( *func ) ( int, int );
};

int main()
{
	int brd[ 500 ], size, query, x1, x2, y1, y2, v;
	char type[ 2 ];
	std::vector<seg> m_seg, M_seg;

	scanf( "%d", &size );
	m_seg.reserve( size );
	M_seg.reserve( size );
	for( int i = 0; i < size; ++i )
	{
		for( int j = 0; j < size; ++j )
			scanf( "%d", brd + j );
		m_seg.emplace_back( brd, 0, size, min );
		M_seg.emplace_back( brd, 0, size, max );
	}
	for( scanf( "%d", &query ); query-- && scanf( "%s", type ); )
	{
		if( type[ 0 ] == 'c' )
		{
			scanf( "%d %d %d", &x1, &y1, &v );
			m_seg[ --x1 ].update( --y1, v );
			M_seg[ x1 ].update( y1, v );
		}
		else
		{
			scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
			int m = 1e9, M = -1;
			for( int i = x1 - 1; i < x2; ++i )
			{
				M = max( M, M_seg[ i ].query( y1 - 1, y2 ) );
				m = min( m, m_seg[ i ].query( y1 - 1, y2 ) );
			}
			printf( "%d %d\n", M, m );
		}
	}
}
