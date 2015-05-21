#include<iostream>
#include<cstring>
#include<string>
#include<map>
using namespace std;

bool endwith( string& A, string B ) // A ends with B
{
	for( int i = 1; i <= B.size(); ++i )
		if( A[ A.size() - i ] != B[ B.size() - i ] )
			return false;
	return true;
}

bool endwith( string& A, string B[], int size )
{
	for( int i = 0; i < size; ++i )
		if( endwith( A, B[ i ] ) )
			return true;
	return false;
}

int main()
{
	int L, N;
	string sing, plur, list[] = { "o", "x", "s", "sh", "ch" };
	map<string,string> dict;

	cin >> L >> N;
	while( L-- )
		cin >> sing >> plur, dict[ sing ] = plur;
	while( N-- )
	{
		cin >> sing;
		if( dict.find( sing ) != dict.end() )
			cout << dict[ sing ] << endl;
		else if( endwith( sing, "y" ) && !strchr( "aieou", sing[ sing.size() - 2 ] ) )
			cout << sing.replace( --sing.end(), sing.end(), "ies" ) << endl;
		else
			cout << sing.append( endwith( sing, list, 5 )? "es" : "s" ) << endl;
	}
}
