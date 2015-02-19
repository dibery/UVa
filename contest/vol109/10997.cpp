#include<bits/stdc++.h>
using namespace std;

struct nation
{
	string name;
	int gold, silver, bronze;
	nation( string& n, int g, int s, int b )
	{
		name = n;
		gold = g;
		silver = s;
		bronze = b;
	}
}

int main()
{
	string n;
	int size, g, s, b;

	while( cin >> size )
	{
		vector<nation> all;
		int medal = 0;
		for( int i = 0; i < size; ++i )
			cin >> n >> g >> s >> b, all.push_back( nation( n, g, s, b ) ), medal += s+g+b;
		for( int i = -30; i 
