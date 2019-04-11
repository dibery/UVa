#include<iostream>
#include<list>
using namespace std;

int main()
{
	list<int>line;
	list<int>::iterator ptr;
	int participate, out, selection = 0, cards[ 20 ];

	while( cin >> participate >> out )
	{
		int current = -1, i;
		for( i = 0; i < 20; ++i )
			cin >> cards[ i ];
		for( i = 1; i <= participate; ++i )
			line.push_back( i );

		while( ++current < 20 )
		{
			ptr = line.begin();
			for( i = 0; ptr != line.end() && line.size() != (unsigned)out; ++i )
			{
				if( i % ( cards[ current ] ) == 0 && i )
				{
					ptr = line.erase( ptr );
					ptr--;
				}
				if( line.size() == (unsigned)out )
					break;
				if( i )
					++ptr;
			}
		}
		cout << "Selection #" << ++selection << endl;
		for( ; line.size(); line.pop_front() )
			cout << line.front() << ( ( line.size() == 1? '\n' : ' ' ) );
		cout << endl;
	}
	return 0;
}

