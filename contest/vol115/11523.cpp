#include<bits/stdc++.h>
using namespace std;

int calc( vector<int>& seg )
{
	int local[ 105 ][ 105 + 1 ] = { { 0 } }, size = seg.size();
	for( int i = 0; i < size; ++i )
		for( int j = 0; j <= size; ++j )
			local[ i ][ j ] = INT_MAX;
	for( int i = 0; i < size; ++i )
		local[ i ][ i ] = 0, local[ i ][ i+1 ] = 1;
	for( int len = 2; len <= size; ++len )
		for( int begin = 0; begin + len <= size; ++begin )
			for( int mbegin = begin; mbegin < begin + len; ++mbegin )
				for( int mend = mbegin; mend <= begin + len; ++mend )
				{
					int tmp = local[ mbegin ][ mend ] + local[ begin ][ mbegin ] + local[ mend ][ begin + len ];
					if( mbegin > begin && mend < begin + len && seg[ mbegin-1 ] == seg[ mend ] )
						--tmp;
					local[ begin ][ begin+len ] = min( local[ begin ][ begin+len ], tmp );
				}
	seg.clear();
	return local[ 0 ][ size ];
}

int main()
{
	int t, size;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		scanf( "%d", &size );
		
		int order[ 105 ] = { 0 }, ans = 0;
		string s;
		map<string,int> yes, no;
		vector<int> seg;

		for( int i = 0; i < size; ++i )
		{
			cin >> s;
			if( isupper( s[ 0 ] ) && no.find( s ) == no.end() )
				no.insert( pair<string,int> ( s, no.size() + 1 ) );
			else if( islower( s[ 0 ] ) && yes.find( s ) == yes.end() )
				yes.insert( pair<string,int> ( s, yes.size() + 1 ) );
			order[ i ] = isupper( s[ 0 ] )? -no[ s ] : yes[ s ];
		}

		for( int i = 0; i <= size; ++i )
			if( i == size || order[ i ] < 0 )
				ans += calc( seg );
			else
				seg.push_back( order[ i ] );

		printf( "Case %d: %d\n", n, ans );
	}
}
