#include<cstdio>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
	for( int box, cmd, t = 0; scanf( "%d %d", &box, &cmd ) == 2; )
	{
		list<int>::iterator it[ 100001 ];
		list<int> chain;
		bool rev = false;
		long long sum = 0;

		for( int i = 1; i <= box; ++i )
			it[ i ] = chain.insert( chain.end(), i );

		for( int type, x, y; cmd-- && scanf( "%d", &type ); )
			if( type == 1 && !rev || type == 2 && rev )
			{
				scanf( "%d %d", &x, &y );
				auto i = it[ x ];
				it[ x ] = chain.insert( it[ y ], *i );
				chain.erase( i );
			}
			else if( type == 2 && !rev || type == 1 && rev )
			{
				scanf( "%d %d", &x, &y );
				auto i = it[ x ];
				it[ x ] = chain.insert( next( it[ y ] ), *i );
				chain.erase( i );
			}
			else if( type == 3 )
			{
				scanf( "%d %d", &x, &y );
				swap( *it[ x ], *it[ y ] );
				swap( it[ x ], it[ y ] );
			}
			else
				rev = !rev;

		for( auto i = chain.begin(); i != chain.end(); ++i, rev = !rev )
			if( !rev )
				sum += *i;
		printf( "Case %d: %lld\n", ++t, sum );
	}
}
