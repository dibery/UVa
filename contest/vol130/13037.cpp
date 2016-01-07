#include<bits/stdc++.h>
#define set unordered_set
using namespace std;

void check( set<int>& a, set<int>& b, set<int>& c )
{
	int uniq = 0, loss = 0;
	set<int> u;

	for( int i: a )
		uniq += b.find( i ) == b.end() && c.find( i ) == c.end();
	for( int i: b )
		if( c.find( i ) != c.end() )
			u.insert( i );
	for( int i: u )
		loss += a.find( i ) == a.end();
	printf( "%d %d\n", uniq, loss );
}

int main()
{
	int t;

	cin >> t;
	for( int n = 1; n <= t; ++n )
	{
		int sa, sb, sc;
		set<int> a, b, c;

		cin >> sa >> sb >> sc;

		for( int i = 0, n; i < sa; ++i )
			scanf( "%d", &n ), a.insert( n );
		for( int i = 0, n; i < sb; ++i )
			scanf( "%d", &n ), b.insert( n );
		for( int i = 0, n; i < sc; ++i )
			scanf( "%d", &n ), c.insert( n );

		printf( "Case #%d:\n", n );
		check( a, b, c );
		check( b, a, c );
		check( c, a, b );
	}
}
