#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	char s[ 1001 ];

	for( scanf( "%d", &t ); t-- && scanf( "%s", s ); puts( "" ) )
	{
		int times[ 26 ] = { 0 }, len;
		vector<char> c;
		vector<int> t;

		for( len = 0; s[ len ]; ++len )
			++times[ s[ len ] - 'a' ];
		
		for( int i = 0; i < 26; ++i )
			if( times[ i ] )
				c.push_back( 'a' + i );

		for( int i = 0; i < len - c.size(); ++i )
			putchar( c.front() );
		for( char C: c )
			putchar( C );
	}
}
