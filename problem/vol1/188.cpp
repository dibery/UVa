#include<iostream>
#include<sstream>
#include<climits>
using namespace std;

int todigit( string& str )
{
	int mul = 1, ret = 0;
	for( int i = str.size() - 1; i >= 0; --i )
	{
		ret += ( str[ i ] - 'a' + 1 ) * mul;
		mul <<= 5;
	}
	return ret;
}

int main()
{
	string str, tmp;

	while( getline( cin, str ) )
	{
		istringstream token( str );
		int size = 0, w[ 13 ] = { 0 }, c = INT_MAX;
		cout << str << endl;
		while( token >> tmp )
			w[ size++ ] = todigit( tmp ), c = min( c, w[ size+1 ] );
		bool wrong = false;
		while( true )
		{
			for( int i = 0; i < size && !wrong; ++i )
				for( int j = i+1; j < size && !wrong; ++j )
					if( c / w[ i ] % size == c / w[ j ] % size )
						wrong = true, c = min( ( c / w[ i ] + 1 ) * w[ i ], ( c / w[ j ] + 1 ) * w[ j ] );
			if( !wrong )
				break;
			wrong = false;
		}
		cout << c << endl << endl;
	}
}
