#include<iostream>
#include<string>
#include<map>
#include<utility>
#include<algorithm>
using namespace std;
const string size[] = { "XXL", "XL", "L", "M", "S", "XS" };
map<string,int> sp;

void dfs( pair<string,string> need[], int man, int per, int give[], bool& ok, int pos = 0 )
{
	if( pos == man || ok )
	{
		ok = true;
		return;
	}
	if( give[ sp[ need[ pos ].first ] ] < per )
	{
		++give[ sp[ need[ pos ].first ] ];
		dfs( need, man, per, give, ok, pos+1 );
		--give[ sp[ need[ pos ].first ] ];
	}
	if( give[ sp[ need[ pos ].second ] ] < per )
	{
		++give[ sp[ need[ pos ].second ] ];
		dfs( need, man, per, give, ok, pos+1 );
		--give[ sp[ need[ pos ].second ] ];
	}
}

int main()
{
	int t, man, shirt;
	pair<string,string> need[ 30 ];

	for( int i = 0; i < 6; ++i )
		sp[ size[ i ] ] = i;

	for( cin >> t; t--; )
	{
		bool ok = false;
		int give[ 6 ] = { 0 };
		cin >> shirt >> man;
		for( int i = 0; i < man; ++i )
			cin >> need[ i ].first >> need[ i ].second;
		dfs( need, man, shirt /= 6, give, ok );
		cout << ( ok? "YES" : "NO" ) << endl;
	}
}
