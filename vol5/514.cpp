#include<iostream>
#include<cstdio>
#include<stack>
#include<list>
using namespace std;

int main()
{
	int size, now;
	bool correct = true;

	while( scanf( "%d%*c", &size ) != EOF && size != 0 )
	{
		while( 1 )
		{
			list<int> order;
			stack<int> rail;
			int process = 1;
			scanf( "%d%*c", &now );
			if( now == 0 )
				break;
			else
				order.push_back( now );
			for( int i = 1; i < size; ++i )
			{
				scanf( "%d%*c", &now );	
				order.push_back( now );
			}
			while( !order.empty() )
				if( order.front() > process )
				{
					while( process < order.front() )
						rail.push( process++ );
					order.pop_front();
					++process;
				}
				else if( order.front() == process )
				{
					order.pop_front();
					++process;
				}
				else//
					if( !rail.empty() && rail.top() == order.front() )
					{
						order.pop_front();
						rail.pop();
					}
					else
					{
						correct = false;
						order.clear();
					}
			while( !rail.empty() )
				rail.pop();
			cout << ( correct? "Yes" : "No" ) << endl;
			correct = true;
		}
		cout << endl;
	}
	return 0;
}
