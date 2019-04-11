#include<cstdio>
#include<queue>

struct team
{
	int people, have;
	bool operator< ( const team& t ) const { return people * t.have < t.people * have; }
	team( int p, int h = 1 ) : people( p ), have( h ) {}
	int ratio() const { return ( people + have - 1 ) / have; }
};

int main()
{
	for( int music, grp; scanf( "%d %d", &music, &grp ) == 2; )
	{
		std::priority_queue<team> proc;

		for( int i = 0, n; i < grp; ++i, --music )
		{
			scanf( "%d", &n );
			proc.push( team( n ) );
		}
		while( music-- )
		{
			team t = proc.top();
			proc.pop();
			proc.push( team( t.people, t.have + 1 ) );
		}
		printf( "%d\n", proc.top().ratio() );
	}
}
