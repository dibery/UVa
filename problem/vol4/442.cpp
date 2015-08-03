#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

pii calc( string s, int& ans, int& ok, pii size[] )
{
	pii a, b;
	int index = 2;

	if( s[ 1 ] == '(' )
		for( int l = 1; l; ++index )
			if( s[ index ] == '(' )
				++l;
			else if( s[ index ] == ')' )
				--l;
	if( s[ 1 ] != '(' )
		a = size[ s[ 1 ] - 'A' ];
	else
		a = calc( s.substr( 1, index - 1 ), ans, ok, size );
	if( s[ index ] == '(' )
		b = calc( s.substr( index, s.size() - index - 1 ), ans, ok, size );
	else
		b = size[ s[ index ] - 'A' ];

	if( a.second != b.first )
		ok = 0;
	else
		ans += a.first * a.second * b.second;
	return pii ( a.first, b.second );
}

int main()
{
	int N;
	char c;
	string s;
	pii size[ 26 ];

	for( scanf( "%d\n", &N ); N--; )
	{
		scanf( "%c", &c );
		scanf( "%d %d\n", &size[ c - 'A' ].first, &size[ c - 'A' ].second );
	}

	for( int ans = 0, ok = 1; getline( cin, s ); ans = 0, ok = 1 )
	{
		if( s.find( '(' ) != string::npos )
			calc( s, ans, ok, size );
		printf( ok? "%d\n" : "error\n", ans );
	}
}
