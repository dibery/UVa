#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main()
{
	map<string,int>point;
	int m, n, pay;
	string word;
	for( cin >> m >> n; m--; point.insert( pair<string,int>( word, pay ) ) )
		cin >> word >> pay;
	while( n-- )
	{
		pay = 0;
		while( cin >> word && strcmp( word.c_str(), "." ) )
			pay += point[ word ];
		cout << pay << endl;
	}
	return 0;
}
