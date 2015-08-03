#include<iostream>
#include<vector>
using namespace std;

int main()
{
	for( string s; cin >> s; )
	{
		vector<string> p1, p2, dp[ 100 ][ 100 ];

		do
			p1.push_back( s );
		while( cin >> s && s != "#" );
		while( cin >> s && s != "#" )
			p2.push_back( s );
		
		int s1 = p1.size(), s2 = p2.size();

		for( int i = 1; i <= s1; ++i )
			for( int j = 1; j <= s2; ++j )
				if( p1[ i-1 ] == p2[ j-1 ] )
				{
					dp[ i ][ j ] = dp[ i-1 ][ j-1 ];
					dp[ i ][ j ].push_back( p1[ i-1 ] );
				}
				else
					dp[ i ][ j ] = dp[ i-1 ][ j ].size() > dp[ i ][ j-1 ].size()? dp[ i-1 ][ j ] : dp[ i ][ j-1 ];
		for( auto i = dp[ s1 ][ s2 ].begin(); i != dp[ s1 ][ s2 ].end(); ++i )
			cout << *i << ( next( i ) == dp[ s1 ][ s2 ].end()? '\n' : ' ' );
	}
}
