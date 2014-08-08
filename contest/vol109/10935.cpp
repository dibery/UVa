#include<cstdio>
#include<queue>
using namespace std;

int main()
{
	int size;

	while( scanf( "%d", &size ) && size )
	{
		queue<int> deck;
		for( int i = 1; i <= size; ++i )
			deck.push( i );
		for( printf( "Discarded cards:%s", size == 1? "" : " " ); deck.size() > 2; deck.pop() )
		{
			printf( "%d, ", deck.front() );
			deck.pop();
			deck.push( deck.front() );
		}
		if( deck.size() == 1 )
			printf( "\nRemaining card: 1\n" );
		else
			printf( "%d\nRemaining card: %d\n", deck.front(), deck.back() );
	}
}
