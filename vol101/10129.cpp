#include<bits/stdc++.h>
#define check( x ) ( count( deg, deg + 26, x ) )
using namespace std;

int main()
{
	int t, word;
	string s;

	for( cin >> t; t-- && cin >> word; )
	{
		int deg[ 26 ] = { 0 };
		bool adj[ 26 ][ 26 ] = { { false } }, vis[ 26 ] = { false }, show[ 26 ] = { false }, ok = true;

		for( int i = 0; i < word; ++i )
		{
			cin >> s;
			int a = s.front() - 'a', b = s.back() - 'a';
			adj[ a ][ b ] = show[ a ] = show[ b ] = true;
			--deg[ a ], ++deg[ b ];
		}

		int first_show = find( show, show + 26, true ) - show;
		if( all_of( deg, deg + 26, [] ( int n ) { return n == 0; } ) );
		else if( check( -1 ) < 2 && check( 1 ) < 2 && all_of( deg, deg + 26, [] ( int n ) { return abs( n ) <= 1; } ) )
		{
			int *p = find( deg, deg + 26, -1 );
			if( p != deg + 26 )
				first_show = p - deg;
		}
		else
			ok = false;

		queue<int> bfs;
		for( bfs.push( first_show ); ok && !bfs.empty(); bfs.pop() )
			if( !vis[ bfs.front() ] )
			{
				vis[ bfs.front() ] = true;
				for( int i = 0; i < 26; ++i )
					if( adj[ bfs.front() ][ i ] && !vis[ i ] )
						bfs.push( i );
			}

		for( int i = 0; i < 26; ++i )
			ok &= !( show[ i ] && !vis[ i ] );
		puts( ok? "Ordering is possible." : "The door cannot be opened." );
	}
}
