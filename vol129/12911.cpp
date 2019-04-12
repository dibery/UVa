#include<bits/stdc++.h>
using namespace std;
typedef vector<long long> vll;
typedef vll::iterator vlli;

void all( vll& v, vll& l )
{
	for( int i = 0; i < v.size(); ++i )
	{
		vll tmp, comb;
		for( vlli j = l.begin(); j != l.end(); ++j )
			tmp.push_back( *j + v[ i ] );
		for( vlli m = l.begin(), n = tmp.begin(); m != l.end() || n != tmp.end(); )
			comb.push_back( n == tmp.end() || m != l.end() && *m <= *n? *m++ : *n++ );
		l.swap( comb );
	}
}

int main()
{
	for( int N, target, n; scanf( "%d %d", &N, &target ) == 2; )
	{
		vll v[ 2 ], la( 1, 0 ), lb( 1, 0 );
		long long ans = 0;

		for( int i = 0; i < N; ++i )
			scanf( "%d", &n ), v[ i % 2 ].push_back( n );

		all( v[ 0 ], la );
		all( v[ 1 ], lb );
		reverse( lb.begin(), lb.end() ); // la: asc, lb: dec

		for( vlli i = la.begin(), j = lb.begin(); i != la.end() && j != lb.end(); ++i )
			if( i == la.begin() || *i != *prev( i ) )
			{
				while( j != lb.end() && *i + *j > target )
					++j;
				if( j == lb.end() || *i + *j != target )
					continue;
				long long La = find_if( i, la.end(), [ i ] ( long long n ) { return n != *i; } ) - i, Lb = find_if( j, lb.end(), [ j ] ( long long n ) { return n != *j; } ) - j;
				ans += La * Lb;
				j += Lb;
				i += La - 1;
			}
		printf( "%lld\n", ans - ( target == 0 ) );
	}
}
