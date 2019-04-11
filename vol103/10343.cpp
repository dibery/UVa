#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const char* list = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/=";

bool input( string& s )
{
	s.clear();
	while( cin.peek() != '#' )
		if( strchr( list, cin.peek() ) )
			s += cin.get();
		else
			cin.get();
	cin.get();
	return !s.empty();
}

int main()
{
	for( string s; input( s ); putchar( '#' ) )
		for( int i = 0; i < s.size(); i += 4 )
		{
			char now[] = { s[ i ], s[ i + 1 ], s[ i + 2 ], s[ i + 3 ] };
			int val[ 4 ], word[ 3 ];

			for( int p = 0; p < 4; ++p )
				val[ p ] = ( strchr( list, now[ p ] ) - list ) % 64;
			word[ 0 ] = val[ 0 ] << 2 | val[ 1 ] >> 4;
			word[ 1 ] = val[ 1 ] % 16 << 4 | val[ 2 ] >> 2;
			word[ 2 ] = val[ 2 ] % 4 << 6 | val[ 3 ];
			for( int p = 0; p < 3; ++p )
				if( word[ p ] )
					printf( "%c", word[ p ] );
		}
}
