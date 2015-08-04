#include<cstdio>
#include<climits>
#include<vector>
using namespace std;

int main()
{
	int t, arrow, target, score[ 50 ];
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		int use[ 301 ] = { 0 }, next[ 301 ] = { 0 };
		fill( use, use+301, INT_MAX );

		scanf( "%d %d", &arrow, &target );
		for( int i = 0; i < arrow; ++i )
			scanf( "%d", score+i ), use[ score[ i ] ] = 1, next[ score[ i ] ] = score[ i ];

		for( int i = 1; i < target; ++i )
			if( use[ i ] != INT_MAX )
				for( int j = 0; j < arrow && i + score[ j ] <= target; ++j )
					if( use[ i ] + 1 < use[ i + score[ j ] ] || use[ i ] + 1 == use[ i + score[ j ] ] && next[ i + score[ j ] ] < score[ j ] )
						use[ i + score[ j ] ] = use[ i ] + 1, next[ i + score[ j ] ] = score[ j ];

		if( use[ target ] == INT_MAX )
			printf( "Case %d: impossible\n", n );
		else
		{
			vector<int> seq;
			for( int p = target; p; p -= next[ p ] )
				seq.push_back( next[ p ] );
			printf( "Case %d: [%u]", n, seq.size() );
			for( int i = 0; i < seq.size(); ++i )
				printf( " %d", seq[ i ] );
			puts( "" );
		}
	}
}
