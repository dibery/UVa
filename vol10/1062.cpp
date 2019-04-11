#include<cstdio>
#include<cstring>
#include<list>
#include<stack>
#include<deque>
using namespace std;

int main()
{
	int t = 0;
	char str[ 1001 ];

	while( gets( str ) && strcmp( str, "end" ) )
	{
		list< stack<char> > containers;
		list< stack<char> >::iterator it;

		for( int i = 0; str[ i ]; ++i )
		{
			for( it = containers.begin(); it != containers.end(); ++it )
				if( it->top() >= str[ i ] )
					break;
			if( it == containers.end() )
				containers.push_back( stack<char>( deque<char>( 1, str[ i ] ) ) );
			else
				it->push( str[ i ] );
		}
		printf( "Case %d: %u\n", ++t, containers.size() );
	}
}
