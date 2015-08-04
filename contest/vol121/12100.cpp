#include<cstdio>
#include<list>
#include<utility>
using namespace std;

int main()
{
	int t, size, pos, in;

	for( scanf( "%d", &t ); t; --t )
	{
		list< pair<int,bool> > queue;
		int time = 0;
		scanf( "%d %d", &size, &pos );
		for( int i = 0; i < size; ++i )
			scanf( "%d", &in ), queue.push_back( pair<int,bool> ( in, i == pos ) );
		while( !queue.empty() )
		{
			pair<int,bool> tmp = queue.front();
			bool ok = true;
			for( list< pair<int,bool> >::iterator i = queue.begin(); i != queue.end() && ok; ++i )
				ok &= i->first <= tmp.first;
			queue.pop_front();
			if( ok )
				if( tmp.second )
					break;
				else
					++time;
			else
				queue.push_back( tmp );
		}
		printf( "%d\n", time+1 );
	}
}
