#include<bits/stdc++.h>
using namespace std;

int main()
{
	for( string s; getline( cin, s ) && s != "0"; )
	{
		stringstream ss( s );
		vector<string> v;

		for( string a; ss >> a; v.push_back( a ) );
		for( int i = 0; i < v.size(); ++i )
			if( isdigit( v[ i ][ 0 ] ) )
			{
				int n = stoi( v[ i ] );
				for( int j = i - 1; ; --j )
				{
					if( v[ j ] != "#" )
						--n;
					if( !n )
					{
						v[ i ] = to_string( i - j );
						break;
					}
				}
			}

		for( int i = 0; i < v.size(); ++i )
			cout << v[ i ] << ( i == v.size() - 1? '\n' : ' ' );
	}
}
