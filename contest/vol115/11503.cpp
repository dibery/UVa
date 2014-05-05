#include<iostream>
#include<cstdio>
#include<list>
#include<set>
using namespace std;

int main()
{
	int t, qnt;
	string a, b;

	for( scanf( "%d", &t ); t--; )
	{
		list< set<string> >net;
		list< set<string> >::iterator it1, it2;
		scanf( "%d\n", &qnt );

		while( qnt-- )
		{
			cin >> a >> b; 
			for( it1 = net.begin(); it1 != net.end(); ++it1 )
				if( it1->find( a ) != it1->end() )
					break;
			for( it2 = net.begin(); it2 != net.end(); ++it2 )
				if( it2->find( b ) != it2->end() )
					break;
			if( it1 == net.end() && it2 == net.end() )
			{
				net.push_back( set<string>() );
				net.back().insert( a );
				net.back().insert( b );
				printf( "%d\n", net.back().size() );
			}
			else if( it1 == net.end() && it2 != net.end() )
				it2->insert( a ), printf( "%d\n", it2->size() );
			else if( it1 != net.end() && it2 == net.end() )
				it1->insert( b ), printf( "%d\n", it1->size() );
			else if( it1 != it2 )
				it1->insert( it2->begin(), it2->end() ), printf( "%d\n", it1->size() ), net.erase( it2 );
			else
				printf( "%d\n", it1->size() );
		}
	}
	return 0;
}
