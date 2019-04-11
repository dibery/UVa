#include<iostream>
#include<map>
#include<regex>
#include<sstream>
using namespace std;

int main()
{
	regex space( "[,.?!]" ), remove( "['\\-]" );
	for( string s; getline( cin, s ); )
	{
		string all;
		map<int,int> count;

		do
			all += s + ( s.back() == '-'? "" : " " );
		while( getline( cin, s ) && s[ 0 ] != '#' );

		all = regex_replace( all, space, string( " " ) );
		all = regex_replace( all, remove, string( "" ) );
		for( stringstream ss( all ); ss >> s; )
			++count[ s.size() ];

		if( count.empty() )
			continue;
		for( auto& i: count )
			cout << i.first << ' ' << i.second << endl;
		cout << endl;
	}
}
