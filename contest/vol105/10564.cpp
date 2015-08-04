#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int n, sum; scanf( "%d %d", &n, &sum ) && n; )
	{
		int glass[ 40 ][ 20 ] = { { 0 } }, len[ 40 ] = { 0 };
		long long int ans = 0;
		string sol;
		map<int,long long int> method[ 40 ][ 20 ];
		map<int,string> path[ 40 ][ 20 ];

		for( int i = n; i; --i )
			len[ n-i ] = i;
		for( int i = 2; i <= n; ++i )
			len[ i+n-2 ] = i;

		for( int i = 0; i < n*2-1; ++i )
			for( int j = 0; j < len[ i ]; ++j )
				scanf( "%d", glass[ i ] + j );

		for( int i = 0; i < n; ++i )
		{
			path[ 0 ][ i ][ glass[ 0 ][ i ] ] = string( 1, 'A' + i );
			method[ 0 ][ i ][ glass[ 0 ][ i ] ] = 1;
		}
		for( int i = 1; i < n; ++i )
			for( int j = 0; j < len[ i ]; ++j )
			{
				for( map<int,long long int>::iterator k = method[ i-1 ][ j ].begin(); k != method[ i-1 ][ j ].end(); ++k )
					method[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second;
				for( map<int,long long int>::iterator k = method[ i-1 ][ j+1 ].begin(); k != method[ i-1 ][ j+1 ].end(); ++k )
					method[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second;

				for( map<int,string>::iterator k = path[ i-1 ][ j ].begin(); k != path[ i-1 ][ j ].end(); ++k )
					path[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second + "R";
				for( map<int,string>::iterator k = path[ i-1 ][ j+1 ].begin(); k != path[ i-1 ][ j+1 ].end(); ++k )
					if( path[ i ][ j ][ k->first + glass[ i ][ j ] ].empty() )
						path[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second + "L";
					else if( path[ i ][ j ][ k->first + glass[ i ][ j ] ] > k->second + "L" )
						path[ i ][ j ][ k->first + glass[ i ][ j ] ] = k->second + "L";
			}
		for( int i = n; i < 2*n+1; ++i )
			for( int j = 0; j < len[ i ]; ++j )
			{
				if( j != len[ i ] - 1 )
				{
					for( map<int,long long int>::iterator k = method[ i-1 ][ j ].begin(); k != method[ i-1 ][ j ].end(); ++k )
						method[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second;
					for( map<int,string>::iterator k = path[ i-1 ][ j ].begin(); k != path[ i-1 ][ j ].end(); ++k )
						path[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second + "L";
				}
				if( j )
				{
					for( map<int,long long int>::iterator k = method[ i-1 ][ j-1 ].begin(); k != method[ i-1 ][ j-1 ].end(); ++k )
						method[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second;
					for( map<int,string>::iterator k = path[ i-1 ][ j-1 ].begin(); k != path[ i-1 ][ j-1 ].end(); ++k )
						if( path[ i ][ j ][ k->first + glass[ i ][ j ] ].empty() )
							path[ i ][ j ][ k->first + glass[ i ][ j ] ] += k->second + "R";
						else if( path[ i ][ j ][ k->first + glass[ i ][ j ] ] > k->second + "R" )
							path[ i ][ j ][ k->first + glass[ i ][ j ] ] = k->second + "R";
				}
			}

		for( int i = 0; i < n; ++i )
		{
			ans += method[ 2*n-2 ][ i ][ sum ];
			if( path[ 2*n-2 ][ i ].find( sum ) != path[ 2*n-2 ][ i ].end() )
					sol = sol.empty()? path[ 2*n-2 ][ i ][ sum ] : min( sol, path[ 2*n-2 ][ i ][ sum ] );
		}
		printf( ans? "%lld\n%d %s\n" : "0\n\n", ans, sol[ 0 ] - 'A', sol.c_str()+1 );
	}
}
