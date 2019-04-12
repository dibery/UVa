#include<cstdio>
#include<algorithm>
using namespace std;

struct problem
{
	int S, G, S_done, G_done;
	bool operator< ( const problem& p ) const
	{
		return S + max( G, p.S ) + p.G < p.S + max( p.G, S ) + G;
	}
};

int main()
{
	for( int n; scanf( "%d", &n ) == 1; )
	{
		problem pb[ n ];

		for( int i = 0; i < n; ++i )
		{
			scanf( "%d", &pb[ i ].S );
			pb[ i ].S_done = pb[ i ].S;
		}
		for( int i = 0; i < n; ++i )
		{
			scanf( "%d", &pb[ i ].G );
			pb[ i ].G_done = pb[ i ].S + pb[ i ].G;
		}
		sort( pb, pb + n );
		for( int i = 1; i < n; ++i )
			pb[ i ].S_done += pb[ i - 1 ].S_done;
		for( int i = 1; i < n; ++i )
			pb[ i ].G_done = max( pb[ i - 1 ].G_done, pb[ i ].S_done ) + pb[ i ].G;
		printf( "%d\n", pb[ n - 1 ].G_done );
	}
}
