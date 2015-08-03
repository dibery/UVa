#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct box
{
	static int dim;
	int len[ 10 ];

	box()
	{
		for( int i = 0; i < dim; ++i )
			scanf( "%d", len + i );
		sort( len, len + dim );
	}

	bool operator< ( const box& rhs ) const
	{
		for( int i = 0; i < dim; ++i )
			if( len[ i ] >= rhs.len[ i ] )
				return false;
		return true;
	}
};
int box::dim;

void dfs( bool adj[ 30 ][ 30 ], int pos, int size, vector<int>& lis, vector<int>& tmp )
{
	tmp.push_back( pos );
	if( tmp.size() > lis.size() )
		lis = tmp;
	for( int i = 0; i < size; ++i )
		if( adj[ pos ][ i ] )
			dfs( adj, i, size, lis, tmp );
	tmp.pop_back();
}

int main()
{
	for( int size; scanf( "%d %d", &size, &box::dim ) == 2; )
	{
		box item[ size ];
		bool adj[ 30 ][ 30 ] = { { false } }, pointed[ 30 ] = { false };
		vector<int> detail, tmp;

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				if( item[ j ] < item[ i ] )
					adj[ j ][ i ] = pointed[ i ] = true;

		for( int i = 0; i < size; ++i )
			if( !pointed[ i ] )
				dfs( adj, i, size, detail, tmp );

		printf( "%d\n", int( detail.size() ) );
		for( int i = 0; i < detail.size(); ++i )
			printf( "%d%c", detail[ i ] + 1, i == detail.size() - 1? '\n' : ' ' );
	}
}
