#include<bits/stdc++.h>
using namespace std;

struct range
{
	double l, r;
	bool mark;
	range( double L, double R ) : l( L ), r( R ) { mark = false; }
	bool operator< ( range c ) const
	{
		if( mark != c.mark )
			return mark < c.mark;
		return abs( r - c.r ) > DBL_EPSILON? r < c.r + DBL_EPSILON : l < c.l + DBL_EPSILON;
	}
};

int main()
{
	for( int n, d, t = 0; scanf( "%d %d", &n, &d ) && n; )
	{
		vector<range> nodes;
		bool wrong = false;
		int ans = 0;

		for( int x, y, i = 0; i < n && scanf( "%d %d", &x, &y ); ++i )
			if( d >= y )
				nodes.emplace_back( x - sqrt( d * d - y * y ), x + sqrt( d * d - y * y ) );
			else
				wrong = true;
		sort( nodes.begin(), nodes.end() );
		if( !wrong )
			for( ; !nodes[ 0 ].mark; sort( nodes.begin(), nodes.end() ), ++ans )
				for( auto& n: nodes )
					if( n.l <= nodes[ 0 ].r + DBL_EPSILON )
						n.mark = true;

		printf( "Case %d: %d\n", ++t, wrong? -1 : ans );
	}
}
