#include<bits/stdc++.h>
using namespace std;
typedef map<int,int> mii;
typedef mii::iterator IT;

bool even( int n ) { return n % 2 == 0; }
bool connect( map<int,int>lnk[], IT skip = map<int,int>().begin() );
void dfs( bool [][ 45 ], bool[], int );
void build( mii[], list<int>&, int, size_t );

int main()
{
	char s[ 100 ];
	int from, to, id, johnny;

	while( gets( s ) && strcmp( s, "0 0" ) )
	{
		map<int,int> road[ 45 ];
		list<int> path;
		int show[ 45 ] = { 0 }, all = 0;

		sscanf( s, "%d %d %d", &from, &to, &id );
		johnny = min( from, to );
		do
		{
			sscanf( s, "%d %d %d", &from, &to, &id );
			road[ from ][ id ] = to;
			road[ to ][ id ] = from;
			++show[ from ], ++show[ to ];
			++all;
		} while( gets( s ) && strcmp( s, "0 0" ) );

		if( all_of( show, show+45, even ) && connect( road ) )
		{
			build( road, path, johnny, all );
			for( list<int>::iterator i = path.begin(); i != path.end(); ++i )
				printf( "%d%s", *i, i == --path.end()? "\n\n" : " " );
		}
		else
			puts( "Round trip does not exist.\n" );
	}
}

bool connect( map<int,int> lnk[], IT skip )
{
	bool adj[ 45 ][ 45 ] = { { false } }, vis[ 45 ] = { false };
	int begin = 0, index;

	for( int i = 1; i < 45; ++i )
		for( IT j = lnk[ i ].begin(); j != lnk[ i ].end(); ++j )
			if( j->first != skip->first )
				adj[ i ][ begin = j->second ] = true;
	dfs( adj, vis, begin );

	for( index = 1; index < 45; ++index )
		if( !lnk[ index ].empty() && !vis[ index ] )
			index = INT_MAX-1;
	return index != INT_MAX;
}

void dfs( bool adj[ 45 ][ 45 ], bool* vis, int p )
{
	vis[ p ] = true;
	for( int i = 1; i < 45; ++i )
		if( !vis[ i ] && adj[ p ][ i ] )
			dfs( adj, vis, i );
}

void build( map<int,int> lnk[], list<int>& seq, int p, size_t all )
{
	while( seq.size() < all )
		for( IT i = lnk[ p ].begin(); i != lnk[ p ].end(); ++i )
			if( lnk[ p ].size() == 1 || connect( lnk, i ) )
			{
				int tmp = p;
				seq.push_back( i->first );
				lnk[ p = i->second ].erase( i->first );
				if( tmp != i->second )
					lnk[ tmp ].erase( i );
				break;
			}
}
