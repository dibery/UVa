#include<cstdio>
#include<algorithm>
using namespace std;
class event
{
	public:
		int start, end;
		event( int s = -1, int e = -1 ) { start = s; end = e; }
		bool operator() ( event* a, event* b ) { return a->end < b->end; }
} obj;

int main()
{
	int t, s, e;
	for( scanf( "%d", &t ); t--; )
	{
		event* day[ 20 ] = { NULL };
		int size = 0, has = 0, last = -1;
		while( scanf( "%d %d", &s, &e ) && s+e )
			day[ size++ ] = new event( s, e );
		sort( day, day+size, obj );
		for( int i = 0; i < size; ++i )
			if( day[ i ]->start >= last )
				last = day[ i ]->end, ++has;
		printf( "%d\n", has );
	}
	return 0;
}
