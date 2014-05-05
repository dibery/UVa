#include<iostream>
#include<cstdio>
#include<list>
#include<set>
using namespace std;

int main()
{
	int t;
	char limit, ver[ 3 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		list< set<char> >graph;
		list< set<char> >::iterator it1, it2;
		set<char>all;
		scanf( "%c%*c", &limit );

		while( gets( ver ) && *ver )
		{
			char a = ver[ 0 ], b = ver[ 1 ];
			all.insert( a ), all.insert( b );
			for( it1 = graph.begin(); it1 != graph.end(); ++it1 )
				if( it1->find( a ) != it1->end() )
					break;
			for( it2 = graph.begin(); it2 != graph.end(); ++it2 )
				if( it2->find( b ) != it2->end() )
					break;
			if( it1 == graph.end() && it2 == graph.end() )
			{
				graph.push_back( set<char>() );
				graph.back().insert( a );
				graph.back().insert( b );
			}
			else if( it1 == graph.end() && it2 != graph.end() )
				it2->insert( a );
			else if( it1 != graph.end() && it2 == graph.end() )
				it1->insert( b );
			else if( it1 != it2 )
				it1->insert( it2->begin(), it2->end() ), graph.erase( it2 );
		}
		printf( t? "%u\n\n" : "%u\n", graph.size() + limit-'A'+1 - all.size() );
	}
	return 0;
}
