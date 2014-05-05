#include<iostream>
using namespace std;

int main()
{
	int t, sub, have;
	cin >> t;

	for( int i = 1; i <= t; ++i )
	{
		cin >> sub;
		string name[ sub ], req;
		int need[ sub ], index = -1;

		for( int k = 0; k < sub; ++k )
			cin >> name[ k ] >> need[ k ];
		cin >> have >> req;
		while( ++index < sub && name[ index ] != req );
		if( index == sub || need[ index ] > have+5 )
			cout << "Case " << i << ": Do your own homework!\n";
		else if( need[ index ] <= have )
			cout << "Case " << i << ": Yesss\n";
		else
			cout << "Case " << i << ": Late\n";
	}

	return 0;
}
