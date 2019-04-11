#include<iostream>
#include<regex>
using namespace std;

int main()
{
	regex e( "[+-]?(\\d+\\.\\d+([eE][+-]?\\d+)?|\\d+[eE][+-]?\\d+)" );
	for( string s; cin >> s && s != "*"; )
		cout << s << " is " << ( regex_match( s, e )? "" : "il" ) << "legal." << endl;
}
