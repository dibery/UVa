#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, len, num[ 100 ], target;

	for( cin >> t; t-- && cin >> len; )
	{
		for( int i = 0; i < len; ++i )
			cin >> num[ i ];
		cin >> target;

		unordered_map<int,string> result[ len ];

		result[ 0 ][ num[ 0 ] ] = "";
		for( int i = 1; i < len; ++i )
			for( auto p: result[ i - 1 ] )
			{
				if( abs( p.first + num[ i ] ) <= 32000 )
					result[ i ][ p.first + num[ i ] ] = p.second + '+';
				if( abs( p.first - num[ i ] ) <= 32000 )
					result[ i ][ p.first - num[ i ] ] = p.second + '-';
				if( abs( p.first * num[ i ] ) <= 32000 )
					result[ i ][ p.first * num[ i ] ] = p.second + '*';
				if( abs( p.first / num[ i ] ) <= 32000 && p.first % num[ i ] == 0 )
					result[ i ][ p.first / num[ i ] ] = p.second + '/';
			}

		if( result[ len - 1 ].find( target ) == result[ len - 1 ].end() )
			cout << "NO EXPRESSION" << endl;
		else
		{
			string& s = result[ len - 1 ][ target ];
			for( int i = 0; i < len - 1; ++i )
				cout << num[ i ] << s[ i ];
			cout << num[ len - 1 ] << '=' << target << endl;
		}
	}
}
