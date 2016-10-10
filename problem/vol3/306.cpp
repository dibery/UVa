#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int n, t, code[ 200 ] = { 0 }; scanf( "%d", &n ) && n; puts( "" ) )
	{
		char msg[ 201 ] = { 0 }, tmp[ 201 ] = { 0 };
		int pos[ 200 ] = { 0 };
		vector<int> cycle[ 200 ];

		for( int i = 0; i < n; --code[ i++ ] )
			scanf( "%d", code + i );
		for( int i = 0; i < n; ++i )
			pos[ code[ i ] ] = i;
		for( int i = 0; i < n; ++i )
			for( cycle[ i ].push_back( i ); code[ cycle[ i ].back() ] != cycle[ i ].front(); )
				cycle[ i ].push_back( code[ cycle[ i ].back() ] );
		for( ; scanf( "%d%*c", &t ) && t; memset( msg, 0, sizeof( msg ) ) )
		{
			gets( msg );
			fill( msg + strlen( msg ), msg + n, ' ' );
			for( int i = 0; i < n; ++i )
				tmp[ cycle[ i ][ t % cycle[ i ].size() ] ] = msg[ i ];
			puts( tmp );
		}
	}
}
