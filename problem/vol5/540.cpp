#include<iostream>
#include<queue>
using namespace std;
short list[ 1000000 ] = { 0 };

int main()
{
	int quant, test = 1;
	while( cin >> quant && quant != 0 )
	{
		queue<int> team[ 1001 ];
		queue<int> order;

		for( int i = 1; i <= quant; ++i )
		{
			int people;
			cin >> people;
			for( int j = 0; j < people; ++j )
			{
				int id;
				cin >> id;
				list[ id ] = i;
			}
		}
		cout << "Scenario #" << test++ << endl;
		string command;
		while( cin >> command && command != "STOP" )
			if( command == "DEQUEUE" )
			{
				cout << team[ order.front() ].front() << endl;
				team[ order.front() ].pop();
				if( team[ order.front() ].empty() )
					order.pop();
			}
			else // if( command == "ENQUEUE" )
			{
				int in;
				cin >> in;
				if( team[ list[ in ] ].empty() )
					order.push( list[ in ] );
				team[ list[ in ] ].push( in );
			}
		cout << endl;
	}
}
