#include<cstdio>
#include<cstdlib>
#include<list>
#include<algorithm>
using namespace std;

void write( int p, int c, int dep, int* h1, int* h2, int* src1, int* src2 )
{
	if( dep > h1[ p ] )
		src2[ p ] = src1[ p ], src1[ p ] = c, h2[ p ] = h1[ p ], h1[ p ] = dep;
	else if( dep > h2[ p ] )
		src2[ p ] = c, h2[ p ] = dep;
}

void DFS1( int pos, int* p, int* h1, int* h2, int* src1, int* src2, list<int>* adj )
{
	h1[ pos ] = h2[ pos ] = 0;
	for( list<int>::iterator i = adj[ pos ].begin(); i != adj[ pos ].end(); ++i )
		if( *i != p[ pos ] )
		{
			p[ *i ] = pos;
			DFS1( *i, p, h1, h2, src1, src2, adj );
			write( pos, *i, h1[ *i ] + 1, h1, h2, src1, src2 );
		}
}

void DFS2( int pos, int* p, int* h1, int* h2, int* src1, int* src2, list<int>* adj )
{
	if( pos != p[ pos ] )
	{
		int x = p[ pos ];
		write( pos, x, src1[ x ] == pos? h2[ x ] + 1 : h1[ x ] + 1, h1, h2, src1, src2 );
	}
	for( list<int>::iterator i = adj[ pos ].begin(); i != adj[ pos ].end(); ++i )
		if( *i != p[ pos ] )
			DFS2( *i, p, h1, h2, src1, src2, adj );
}

int main()
{
	for( int node, qnt; scanf( "%d", &node ) == 1; puts( "" ) )
	{
		list<int> adj[ node ];
		int src1[ 5000 ] = { 0 }, src2[ 5000 ] = { 0 }, h1[ 5000 ] = { 0 }, h2[ 5000 ] = { 0 }, parent[ 5000 ] = { 0 };

		for( int from = 0, to; from < node; ++from )
			for( scanf( "%d", &qnt ); qnt--; )
				scanf( "%d", &to ), adj[ from ].push_back( to-1 ), adj[ to-1 ].push_back( from );
		DFS1( 0, parent, h1, h2, src1, src2, adj );
		DFS2( 0, parent, h1, h2, src1, src2, adj );

		int H = *h1, D = *h1; // height, diameter

		for( int i = 1; i < node; ++i )
			H = min( H, h1[ i ] ), D = max( D, h1[ i ] );
		printf( "Best Roots  :" );
		for( int i = 0; i < node; ++i )
			if( h1[ i ] == H )
				printf( " %d", i+1 );
		printf( "\nWorst Roots :" );
		for( int i = 0; i < node; ++i )
			if( h1[ i ] == D )
				printf( " %d", i+1 );
	}
}
