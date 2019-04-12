#include<iostream>
#include<algorithm>
#include<cctype>
using namespace std;
const string letter = "abcdefghijklmnopqrstuvwxyz-";

string& lower( string& s )
{
	for( size_t i = 0; i < s.size(); ++i )
		s[ i ] = tolower( s[ i ] );
	return s;
}

int len( string& str )
{
	size_t M = 0;
	string tmp;
	for( size_t pos = str.find_first_of( letter ); pos != str.npos;
			pos = str.find_first_of( letter, str.find_first_not_of( letter, pos ) ) )
		if( ( str.find_first_not_of( letter, pos ) == str.npos? str.size() : str.find_first_not_of( letter, pos ) ) - pos > M )
			tmp = str.substr( pos, str.find_first_not_of( letter, pos ) );
	str = tmp;
	return tmp.size();
}

int main()
{
	string in, ans;
	int max = 0;

	while( cin >> in && in != "E-N-D" )
		if( len( lower( in ) ) > max )
			max = len( ans = in );
	cout << ans << endl;
}
