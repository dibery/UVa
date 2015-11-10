#include<cstdio>
#include<vector>
#include<map>
#include<utility>
#define N 31624
using namespace std;

int main()
{
	vector<long long> P[ N ];
	map<int,pair<int,int> > lookup;

	for( int i = 1; i < N; ++i )
		P[ i ].push_back( i );
	for( int i = 2; i < N; ++i )
		for( int j = 1; j < i; ++j )
		{
			P[ i ].push_back( P[ i ].back() * ( i - j ) );
			if( P[ i ].back() > 1e9 )
				break;
		}
	for( int i = 0; i < N; ++i )
		for( int j = 0; j < P[ i ].size(); ++j )
			if( P[ i ][ j ] <= 1e9 && lookup.find( P[ i ][ j ] ) == lookup.end() )
				lookup[ P[ i ][ j ] ] = make_pair( i, i-j-1 );

	for( int n, t = 0; scanf( "%d", &n ) == 1; )
		if( n == 1 )
			printf( "Case %d: Impossible\n", ++t );
		else if( lookup.find( n ) == lookup.end() )
			printf( "Case %d: %d %d\n", ++t, n, n-1 );
		else
			printf( "Case %d: %d %d\n", ++t, lookup[ n ].first, lookup[ n ].second );
}
