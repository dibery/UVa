#include<cstdio>
#include<algorithm>

struct stat
{
	long long vote;
	int id;
	bool operator< ( const stat& rhs ) { return rhs.vote != vote? vote > rhs.vote : id < rhs.id; }
	stat() { vote = id = 0; }
};

int main()
{
	int t, cand, land;
	double rate[ 100000 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %d", &cand, &land ); )
	{
		stat vote[ 100000 ];
		long long total = 0;

		for( int i = 0; i < cand; ++i )
			vote[ i ].id = i + 1;
		for( int i = 0, tmp; i < land; ++i )
		{
			for( int j = 0; j < cand; ++j )
				scanf( "%lf", rate + j );
			scanf( "%d", &tmp );
			total += tmp;
			for( int j = 0; j < cand; ++j )
				vote[ j ].vote += rate[ j ] * tmp / 100 + .1;
		}
		std::sort( vote, vote + cand );
		if( vote[ 0 ].vote * 1000 >= 501 * total )
			printf( "%d %lld\n", vote[ 0 ].id, vote[ 0 ].vote );
		else
			printf( "%d %lld\n%d %lld\n", vote[ 0 ].id, vote[ 0 ].vote, vote[ 1 ].id, vote[ 1 ].vote );
		printf( t? "\n" : "" );
	}
}
