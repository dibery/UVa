#include<bits/stdc++.h>
#define N 522
using namespace std;

int karp( list<int>*, int, int ), bfs( list<int>*, int[], int[][N], int, int );
int t, man, site, limit, lnk, cap[ N ][ N ];

int main()
{
	for( scanf( "%d", &t ); t--; )
	{
		list<int> adj[ N ];

		scanf( "%d %d %d %d", &man, &site, &limit, &lnk );
		memset( cap, 0, sizeof( cap ) );
		for( int i = 0, a, b; i < lnk; ++i )
			scanf( "%d %d", &a, &b ), adj[ a ].push_back( man+b ), cap[ a ][ man+b ] = 1;
		for( int i = 1; i <= man; ++i )
			adj->push_back( i ), cap[ 0 ][ i ] = 1;
		for( int i = man+1; i <= man+site; ++i )
			adj[ i ].push_back( man+site+1 ), cap[ i ][ man+site+1 ] = limit;

		printf( "%d\n", karp( adj, 0, man+site+1 ) );
	}
}

int karp( list<int> adj[], int s, int t )
{
	int flow[ N ][ N ] = { { 0 } }, res[ N ][ N ] = { { 0 } }, prev[ N ] = { 0 }, f, df;
	memcpy( res, cap, sizeof( cap ) );

	for( f = 0; df = bfs( adj, prev, res, s, t ); f += df )
		for( int i = prev[ t ], j = t; i != j; i = prev[ j = i ] )
		{
			flow[ i ][ j ] += df;
			flow[ j ][ i ] -= df;
			res[ i ][ j ] = cap[ i ][ j ] - flow[ i ][ j ];
			res[ j ][ i ] = cap[ j ][ i ] - flow[ j ][ i ];
		}

	return f;
}

int bfs( list<int> adj[], int prev[], int res[][N], int s, int t )
{
	queue<int> Q;
	bool vis[ N ] = { false };
	int current[ N ];

	vis[ s ] = true;
	prev[ s ] = s;
	current[ s ] = INT_MAX;
	Q.push( s );

	while( !Q.empty() )
	{
		int p = Q.front();
		Q.pop();

		for( list<int>::iterator i = adj[ p ].begin(); i != adj[ p ].end(); ++i )
			if( !vis[ *i ] && res[ p ][ *i ] > 0 )
			{
				vis[ *i ] = true;
				prev[ *i ] = p;
				current[ *i ] = min( current[ p ], res[ p ][ *i ] );
				Q.push( *i );
				if( *i == t )
					return current[ t ];
			}
	}
	return 0;
}