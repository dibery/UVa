#include<cstdio>
#include<algorithm>
#include<list>
using namespace std;

int main()
{
	for ( int man, cmd, id, T = 0; scanf( "%d %d%*c", &man, &cmd ) && man; )
	{
		printf( "Case %d:\n", ++T );
		list<int> stand;

		for ( int i = 1; i <= min( 1000, man ); ++i )
			stand.push_back( i );
		for ( char type; cmd-- && scanf( "%c%*c", &type ); )
			if ( type == 'N' )
			{
				printf( "%d\n", stand.front() );
				stand.push_back( stand.front() );
				stand.erase( stand.begin() );
			}
			else
			{
				scanf( "%d%*c", &id );
				auto p = find( stand.begin(), stand.end(), id );
				if ( p != stand.end() )
					stand.erase( find( stand.begin(), stand.end(), id ) );
				stand.push_front( id );
			}
	}
}
