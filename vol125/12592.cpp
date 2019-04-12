#include<iostream>
#include<map>
using namespace std;

int main()
{
	int slogan, query;
	string to, from;
	map<string,string> dict;
	
	for( cin >> slogan, cin.get(); slogan--; )
	{
		getline( cin, from );
		getline( cin, to );
		dict[ from ] = to;
	}
	for( cin >> query, cin.get(); query--; )
	{
		getline( cin, from );
		cout << dict[ from ] << endl;
	}
}
