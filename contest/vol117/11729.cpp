#include<cstdio>
#include<algorithm>
using namespace std;

class soldier
{
	public:
		soldier( int b = 0, int j = 0 ) { brief = b; job = j; }
		int time() const { return brief + job; }
		bool operator< ( const soldier& cmp ) const { return brief + max( job, cmp.time() ) < cmp.brief + max( cmp.job, time() ); }
		int brief, job;
};

int main()
{
	int size, t = 0;

	while( scanf( "%d", &size ) && size )
	{
		soldier all[ size ];
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &all[ i ].brief, &all[ i ].job );
		sort( all, all+size );
		int exp = 0, done = 0;
		for( int i = 0; i < size; ++i )
			done = max( done, exp + all[ i ].time() ), exp += all[ i ].brief;
		printf( "Case %d: %d\n", ++t, done );
	}
}
