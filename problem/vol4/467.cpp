#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t = 0;
	for( string s; getline( cin, s ); )
	{
		stringstream ss( s );
		vector<int> len;
		bool light[ 10 ];

		for( int n; ss >> n; len.push_back( n ) );
		sort( len.begin(), len.end() );
		int disp = len[ 0 ] - 5, sync = -1;

		for( int i = disp; i <= 3600 && sync == -1; ++i )
		{
			transform( len.begin(), len.end(), light, [ i ] ( int p ) { return i % ( 2 * p ) < p - 5; } );
			if( all_of( light, light + len.size(), [] ( bool b ) { return b; } ) )
				sync = i;
		}
		if( ~sync )
			printf( "Set %d synchs again at %d minute(s) and %d second(s) after all turning green.\n", ++t, sync / 60, sync % 60 );
		else
			printf( "Set %d is unable to synch after one hour.\n", ++t );
	}
}
