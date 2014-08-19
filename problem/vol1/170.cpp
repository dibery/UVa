#include<iostream>
#include<iomanip>
#include<stack>
#include<string>
using namespace std;
const string face = "A23456789TJQK";

int main()
{
	string deck[ 52 ], last;

	while( cin >> deck[ 51 ] && deck[ 51 ] != "#" )
	{
		stack<string> clock[ 13 ];
		int now = 12, turn = 0;

		for( int i = 50; i >= 0; --i )
			cin >> deck[ i ];
		for( int i = 0; i < 52; ++i )
			clock[ i % 13 ].push( deck[ i ] );

		while( !clock[ now ].empty() )
		{
			last = clock[ now ].top();
			clock[ now ].pop();
			now = face.find( last[0] );
			++turn;
		}
		cout << setw(2) << setfill('0') << turn << ',' << last << endl;
	}
}
