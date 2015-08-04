#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<vector>
using namespace std;
int field[ 1001 ][ 1001 ], t;
string sa, sb, s;

int main()
{
	while( getline( cin, sa ) && getline( cin, sb ) )
	{
		if( sa.empty() || sb.empty() )
		{
			printf( "%2d. Blank!\n", ++t );
			continue;
		}
		for( int i = 0; i < sa.size(); ++i )
			if( !isalnum( sa[ i ] ) )
				sa[ i ] = ' ';
		for( int i = 0; i < sb.size(); ++i )
			if( !isalnum( sb[ i ] ) )
				sb[ i ] = ' ';
		stringstream ssa( sa ), ssb( sb );
		vector<string> a, b;
		while( ssa >> s )
			a.push_back( s );
		while( ssb >> s )
			b.push_back( s );

		int h = a.size(), w = b.size();
		if( !h || !w )
		{
			printf( "%2d. Length of longest match: 0\n", ++t );
			continue;
		}

		memset( field, 0, sizeof( field ) );

		for( int i = 0; i < w; ++i )
			field[ 0 ][ i ] = a[ 0 ] == b[ i ] || i && field[ 0 ][ i-1 ];
		for( int i = 1; i < h; ++i )
			field[ i ][ 0 ] = field[ i-1 ][ 0 ] || a[ i ] == b[ 0 ];
		for( int i = 1; i < h; ++i )
			for( int j = 1; j < w; ++j )
				if( a[ i ] == b[ j ] )
					field[ i ][ j ] = field[ i-1 ][ j-1 ]+1;
				else
					field[ i ][ j ] = std::max( field[ i-1 ][ j ], field[ i ][ j-1 ] );
		printf( "%2d. Length of longest match: %d\n", ++t, field[ h-1 ][ w-1 ] );
	}
}
