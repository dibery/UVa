#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

int main()
{
	int t;
	map<ull,map<ull,ull>> comb;

	for( ull i = 5; i < 12447; ++i )
	{
		ull c = i * ( i - 1 ) * ( i - 2 ) * ( i - 3 ) / 24;
		for( ull j = 4; j * 2 <= i && c <= 1e15; ++j )
			comb[ c ][ i ] = j, c = c * ( i - j ) / ( j + 1 );
	}
	
	scanf( "%d", &t );
	for( ull n, r; t-- && scanf( "%llu", &n ); )
	{
		r = cbrt( n * 6 );
		if( r * ( r + 1 ) * ( r + 2 ) / 6 == n )
			comb[ n ][ r + 2 ] = 3;
		r = sqrt( n * 2 );
		if( r * ( r + 1 ) / 2 == n )
			comb[ n ][ r + 1 ] = 2;
		comb[ n ][ n ] = 1;
		int size = comb[ n ].size() * 2;
		for( auto& p: comb[ n ] )
			if( p.second * 2 == p.first )
				--size;
		printf( "%d\n", size );
		for( auto m = comb[ n ].begin(); m != comb[ n ].end(); ++m )
			if( m->second * 2 != m->first )
				printf( "(%llu,%llu) (%llu,%llu)%c", m->first, m->second, m->first, m->first - m->second, next( m ) == comb[ n ].end()? '\n' : ' ' );
			else
				printf( "(%llu,%llu)%c", m->first, m->second, next( m ) == comb[ n ].end()? '\n' : ' ' );
	}
}
