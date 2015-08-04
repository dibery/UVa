#include<bits/stdc++.h>
using namespace std;

struct ans
{
	string val;
	int mod;
	static int N;
	ans( string s, int m = 0 ) { val = s; mod = m; }
};
int ans::N = 0;

int main()
{
	for( char s[ 11 ]; scanf( "%s %d", s, &ans::N ) && ans::N; )
	{
		ans* sol[ 100000 ] = { NULL };
		queue<ans*> bfs;

		reverse( s, s + strlen( s ) );
		for( int i = 0, t; s[ i ]; ++i )
			if( s[ i ] != '0' && !sol[ t = ( s[ i ] - '0' ) % ans::N ] )
			{
				sol[ t ] = new ans( string( 1, s[ i ] ), t );
				bfs.push( sol[ t ] );
			}

		for( ; !*sol && !bfs.empty(); bfs.pop() )
			for( int i = 0, t; s[ i ]; ++i )
				if( !sol[ t = ( bfs.front()->mod * 10 + s[ i ] - '0' ) % ans::N ] )
				{
					sol[ t ] = new ans( bfs.front()->val + string( 1, s[ i ] ), t );
					bfs.push( sol[ t ] );
				}

		puts( *sol? sol[ 0 ]->val.c_str() : "impossible" );
		for( int i = 0; i < ans::N; ++i )
			if( sol[ i ] )
				delete sol[ i ];
	}
}
