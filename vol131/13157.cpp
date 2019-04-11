#include<bits/stdc++.h>
using namespace std;

const int N = 100000, MOD = 1000000007;
int init[] = { 0, 2, 5, 7 }, t, coin, cell;
bool prime[ N ];
vector<vector<int>> layout;

int main()
{
	// Find primes
	fill( prime + 2, prime + N, true );
	for( int i = 4; i < N; i += 2 )
		prime[ i ] = false;
	for( int i = 3; i * i <= N; i += 2 )
		if( prime[ i ] )
			for( int j = i * i; j < N; j += i + i )
				prime[ j ] = false;

	// Find possible patterns
	layout.push_back( vector<int>( init, init + 1 ) );
	layout.push_back( vector<int>( init, init + 2 ) );
	layout.push_back( vector<int>( init, init + 4 ) );
	for( int i = 3; i < N; i += 2 )
		if( prime[ i ] )
		{
			init[ 1 ] = i;
			layout.push_back( vector<int>( init, init + 2 ) );
			if( prime[ i - 2 ] )
			{
				init[ 1 ] = 2;
				init[ 2 ] = i;
				layout.push_back( vector<int>( init, init + 3 ) );
				init[ 1 ] = i - 2;
				layout.push_back( vector<int>( init, init + 3 ) );
			}
		}

	cin >> t;
	for( int n = 1; n <= t && cin >> cell >> coin; ++n )
	{
		long long ans = 0, assign[ 4 ] = { 1 };
		for( int i = 1; i < 4; ++i )
			assign[ i ] = assign[ i - 1 ] * ( coin - i ) / i;
		for( auto l: layout )
			ans += assign[ l.size() - 1 ] % MOD * max( 0, cell - l.back() ) % MOD;
		printf( "Case %d: %lld\n", n, ans % MOD );
	}
}
