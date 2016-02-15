#include<iostream>
#include<sstream>
using namespace std;

int main()
{
	int t, len, set;

	for( cin >> t; t--; )
	{
		int status[ 111 ] = { 0 }, n;
		bool found = false;

		cin >> len >> set;
		cin.get();
		for( int i = 0; i < set; ++i )
		{
			string s;

			getline( cin, s );
			for( stringstream ss( s ); ss >> n; )
				status[ i ] |= 1 << n;
		}

		for( int i = 1; i < 1 << len && !found; ++i )
		{
			bool ok = true;
			for( int j = 0; j < set && ok; ++j )
				ok &= ( status[ j ] & i ) != 0 && ( status[ j ] & i ) != status[ j ];
			found |= ok;
		}
		cout << ( found? 'Y' : 'N' );
	}
}
