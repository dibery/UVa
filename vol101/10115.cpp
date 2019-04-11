#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int rule; cin >> rule && rule; )
	{
		string a[ 10 ], b[ 10 ], str;

		getline( cin, *a );
		for( int i = 0; i < rule; ++i )
			getline( cin, a[ i ] ), getline( cin, b[ i ] );

		getline( cin, str );
		for( int i = 0; i < rule; ++i )
			while( str.find( a[ i ] ) != str.npos )
				str.replace( str.find( a[ i ] ), a[ i ].size(), b[ i ] );

		cout << str << endl;
	}
}
