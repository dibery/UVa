#include<iostream>
#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	string query, eh = "eh";
	char tmp[ 25 ], native[ 12 ], foreign[ 12 ];
	map<string,string>dict;

	while( gets( tmp ) && *tmp )
	{
		sscanf( tmp, "%s %s", native, foreign );
		dict.insert( pair<string,string>( string( foreign ), string( native ) ) );
	}
	while( cin >> query )
		cout << ( dict.find( query ) == dict.end()? eh : dict[ query ] ) << endl;
}
