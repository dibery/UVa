#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

bool anag( string a, string b )
{
	sort( a.begin(), a.end() );
	sort( b.begin(), b.end() );
	if( a.rfind( " " ) != a.npos )
		a.erase( a.begin(), a.begin() + a.rfind( " " ) + 1 );
	if( b.rfind( " " ) != b.npos )
		b.erase( b.begin(), b.begin() + b.rfind( " " ) + 1 );
	return a == b;
}

int main()
{
	int t;
	string in;
	cin >> t;
	cin.get();
	cin.get();

	while( t-- )
	{
		vector<string> list;

		while( getline( cin, in ) && in.length() != 0 )
			list.push_back( in );
		sort( list.begin(), list.end() );
		for( int i = 0; i < list.size(); ++i )
			for( int j = i+1; j < list.size(); ++j )
				if( anag( list[ i ], list[ j ] ) )
					cout << min( list[ i ], list[ j ] ) << " = " << max( list[ i ], list[ j ] ) << endl;
		if( t )
			cout << endl;
	}
}
