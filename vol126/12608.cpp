#include<iostream>
#include<list>
using namespace std;
struct node
{
	int pos, trash;
}tmp;

int main()
{
	int t, cap, point;
	cin >> t;

	while( t-- )
	{
		int truck = 0, dist = 0;
		list<node> place;
		cin >> cap >> point;
		for( int i = 0; i < point; ++i )
			cin >> tmp.pos >> tmp.trash, place.push_back( tmp );
		while( !place.empty() )
			if( truck + place.front().trash < cap )
				truck += place.front().trash, place.pop_front();
			else if( truck + place.front().trash == cap )
				dist += 2 * place.front().pos, place.pop_front(), truck = 0;
			else
				dist += 2 * place.front().pos, truck = 0;
		cout << ( truck? dist + 2 * tmp.pos : dist ) << endl;
	}

	return 0;
}
