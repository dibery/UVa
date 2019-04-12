#include<iostream>
using namespace std;

int main()
{
	int t, action;

	for( cin >> t; t-- && cin >> action; )
	{
		int pos = 0;					// robot position
		string cmd[ 101 ];		// command

		for( int i = 1; i <= action; ++i )
		{
			cin >> cmd[ i ];
			if( cmd[ i ] == "LEFT" )
				--pos;
			else if( cmd[ i ] == "RIGHT" )
				++pos;
			else	// SAME
			{
				string tmp;				// used to store "AS"
				int id;
				cin >> tmp >> id;
				if( cmd[ id ] == "LEFT" )
					--pos;
				else if( cmd[ id ] == "RIGHT" )
					++pos;
				cmd[ i ] = cmd[ id ];
			}
		}
		cout << pos << endl;
	}
}
