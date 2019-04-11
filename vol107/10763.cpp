#include<iostream>
#include<set>
#include<climits>
using namespace std;

int main()
{
	long long size, from, to;

	while( cin >> size && size )
	{
		multiset<long long> ex;
		for( int i = 0; i < size; ++i )
		{
			cin >> from >> to;
			if( ex.find( to * INT_MAX + from ) != ex.end() )
				ex.erase( ex.find( to * INT_MAX + from ) );
			else
				ex.insert( from * INT_MAX + to );
		}
		cout << ( ex.empty()? "YES" : "NO" ) << endl;
	}
}
