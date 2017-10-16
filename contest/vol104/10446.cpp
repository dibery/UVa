#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>,unsigned long long> ans;

unsigned long long trib( int n, int back )
{
	auto p = make_pair( n, back );
	if( ans.find( p ) != ans.end() )
		return ans[ p ];
	if( n <= 0 )
		return ans[ p ] = 1;
	if( n == 1 )
		return ans[ p ] = 1;

	unsigned long long val = 1;
	for( int i = 1; i <= back; ++i )
		val += trib( n - i, back );
	return ans[ p ] = val;
}

int main()
{
	for( int t = 0, n, back; scanf( "%d %d", &n, &back ) && n <= 60; )
		printf( "Case %d: %llu\n", ++t, trib( n, back ) );
}
