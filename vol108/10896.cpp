#include<bits/stdc++.h>
using namespace std;

bool ok( char* match, vector<string>& dict, int offset )
{
	for( auto& i: dict )
		if( i.size() == strlen( match ) )
			for( int j = 0; ; ++j )
				if( match[ j ] && ( i[ j ] - match[ j ] + 26 ) % 26 != offset )
					break;
				else if( !match[ j ] )
					return true;
	return false;
}

int main()
{
	int t;
	char str[ 80 ], match[ 80 ];

	for( scanf( "%d\n", &t ); t--; puts( "" ) )
	{
		stringstream ss( gets( str ) );
		gets( match );
		vector<string> dict;

		while( ss >> str )
			dict.emplace_back( str );
		for( int i = 0; i < 26; ++i )
			if( ok( match, dict, i ) )
				putchar( 'a' + i );
	}
}
