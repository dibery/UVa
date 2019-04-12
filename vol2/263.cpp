#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( string s; cin >> s && s != "0"; )
	{
		set<int> vis;

		printf( "Original number was %s\n", s.c_str() );
		while( true )
		{
			string asc = s, desc = s;

			sort( asc.begin(), asc.end() );
			sort( desc.begin(), desc.end(), greater<char>() );

			int a = stoi( asc ), b = stoi( desc );

			printf( "%d - %d = %d\n", b, a, b - a );
			if( vis.find( b - a ) == vis.end() )
				vis.insert( b - a );
			else
				break;
			s = to_string( b - a );
		}
		printf( "Chain length %u\n\n", vis.size() );
	}
}
