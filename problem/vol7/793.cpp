#include<cstdio>
#include<list>
#include<set>
using namespace std;

int main()
{
	int t, qnt, a, b;
	char cmd[ 50 ] = { 0 }, type;

	for( scanf( "%d", &t ); t--; puts( t? "\n" : "" ) )
	{
		int good = 0, bad = 0;
		list< set<int> >net;
		list< set<int> >::iterator it1, it2;
		scanf( "%d\n", &qnt );

		while( gets( cmd ) && *cmd )
		{
			sscanf( cmd, "%c %d %d", &type, &a, &b );
			for( it1 = net.begin(); it1 != net.end(); ++it1 )
				if( it1->find( a ) != it1->end() )
					break;
			for( it2 = net.begin(); it2 != net.end(); ++it2 )
				if( it2->find( b ) != it2->end() )
					break;
			if( type == 'c' )
				if( it1 == net.end() && it2 == net.end() )
				{
					net.push_back( set<int>() );
					net.back().insert( a );
					net.back().insert( b );
				}
				else if( it1 == net.end() && it2 != net.end() )
					it2->insert( a );
				else if( it1 != net.end() && it2 == net.end() )
					it1->insert( b );
				else
				{
					if( it1 != it2 )
					it1->insert( it2->begin(), it2->end() ), net.erase( it2 );
				}
			else//
				if( a == b )
					++good;
				else if( it1 == it2 && it1 != net.end() )
					++good;
				else
					++bad;
		}
		printf( "%d,%d", good, bad );
	}
	return 0;
}
