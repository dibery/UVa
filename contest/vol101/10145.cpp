#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t, trid, item;
	char mode, s[ 100 ];

	for( scanf( "%d\n", &t ); t--; gets( s ) )
	{
		set<int> ignore;
		map<int,int> mutex;
		map< int, set<int> > shared;

		while( gets( s ) && *s != '#' )
		{
			sscanf( s, "%c %d %d", &mode, &trid, &item );
			if( ignore.find( trid ) != ignore.end() )
				puts( "IGNORED" );
			else if( mode == 'S' )
				if( mutex.find( item ) != mutex.end() )
					if( mutex[ item ] != trid )
						puts( "DENIED" ), ignore.insert( trid );
					else
						puts( "GRANTED" );
				else
					puts( "GRANTED" ), shared[ item ].insert( trid );
			else //X
				if( shared.find( item ) != shared.end() )
					if( shared[ item ].size() > 1 || *shared[ item ].begin() != trid )
						puts( "DENIED" ), ignore.insert( trid );
					else
						puts( "GRANTED" ), mutex[ item ] = trid;
				else // not in shared
					if( mutex.find( item ) == mutex.end() || mutex[ item ] == trid )
						puts( "GRANTED" ), mutex[ item ] = trid;
					else
						puts( "DENIED" ), ignore.insert( trid );
		}
		if( t )
			puts( "" );
	}
}
