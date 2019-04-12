#include<cstdio>
#include<algorithm>
using namespace std;
class node
{
	public:
		int me, opp;
		node( int m = 0, int o = 0 ) { me = m; opp = o; }
		bool operator() ( const node* a, const node* b ) { return a->opp - a->me < b->opp - b->me; }
} obj;
node *contest[ 1000005 ];

int main()
{
	int match, buy, m, o;

	while( scanf( "%d %d", &match, &buy ) == 2 )
	{
		int point = 0, size = 0;
		
		for( int i = 0; i < match; ++i )
		{
			scanf( "%d %d", &m, &o );
			contest[ size++ ] = new node( m, o );
		}
		sort( contest, contest + size, obj );

		for( int i = 0; i < size; ++i )
		{
			if( contest[ i ]->me > contest[ i ]->opp )
				point += 3;
			else if( contest[ i ]->me + buy > contest[ i ]->opp )
			{
				buy -= contest[ i ]->opp - contest[ i ]->me + 1;
				point += 3;
			}
			else if( contest[ i ]->me + buy == contest[ i ]->opp )
			{
				buy -= contest[ i ]->opp - contest[ i ]->me;
				++point;
			}
			else
				break;
			delete contest[ i ];
			contest[ i ] = NULL;
		}
		printf( "%d\n", point );
	}
	return 0;
}
