#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int t, size, cmd, brd[ 10 ][ 10 ], a, b;
	string type;

	cin >> t;
	for( int T = 1; T <= t && cin >> size; ++T )
	{
		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				scanf( "%1d", brd[ i ] + j );
		for( cin >> cmd; cmd-- && cin >> type; )
			if( type == "inc" )
				for( int i = 0; i < size; ++i )
					for( int j = 0; j < size; ++j )
						++brd[ i ][ j ] %= 10;
			else if( type == "dec" )
				for( int i = 0; i < size; ++i )
					for( int j = 0; j < size; ++j )
						( brd[ i ][ j ] += 9 ) %= 10;
			else if( type == "transpose" )
				for( int i = 0; i < size; ++i )
					for( int j = 0; j < i; ++j )
						swap( brd[ i ][ j ], brd[ j ][ i ] );
			else if( type == "row" && cin >> a >> b )
				for( int i = 0; i < size; ++i )
					swap( brd[ a - 1 ][ i ], brd[ b - 1 ][ i ] );
			else if( type == "col" && cin >> a >> b )
				for( int i = 0; i < size; ++i )
					swap( brd[ i ][ a - 1 ], brd[ i ][ b - 1 ] );
		cout << "Case #" << T << endl;
		for( int i = 0; i < size; ++i, cout << endl )
			for( int j = 0; j < size; ++j )
				cout << brd[ i ][ j ];
		if( t )
			cout << endl;
	}
}
