#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( int size; cin >> size && size; )
	{
		string name[ 1000 ], a, b;

		for( int i = 0; i < size; ++i )
			cin >> name[ i ];
		sort( name, name + size );
		a = name[ size / 2 - 1 ];
		b = name[ size / 2 ];
		for( size_t p = 0; p < a.size() && p < b.size(); ++p )
			if( p == a.size() - 1 )
				cout << a << endl;
			else if( p == b.size() - 1 )
				if( b[ p ] > a[ p ] + 1 )
					cout << a.substr( 0, p ) << ++a[ p ] << endl;
				else
				{
					for( ++p; p < a.size() && a[ p ] == 'Z'; ++p );
					cout << a.substr( 0, p );
					if( p < a.size() )
						if( p == a.size() - 1 )
							cout << a[ p ];
						else
							cout << ++a[ p ];
					cout << endl;
				}
			else if( a[ p ] != b[ p ] )
			{
				cout << a.substr( 0, p ) << ++a[ p ] << endl;
				break;
			}
	}
}
