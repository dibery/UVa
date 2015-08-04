#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( char in[ 101 ]; gets( in ); )
	{
		string s = in;
		set<string> window[ 101 ];
		int offend;
		bool ok = true;

		for( offend = 0; offend < s.length() && ok; ++offend )
			for( int i = 0; i <= offend && ok; ++i )
			{
				window[ i ].insert( s.substr( offend - i, i + 1 ) );
				if( window[ i ].size() > i+2 )
					ok = false;
			}

		if( !ok )
			printf( "NO:%d\n", offend );
		else
			puts( "YES" );
	}
}
