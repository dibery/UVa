#include<bits/stdc++.h>
using namespace std;

int big_mod( unsigned long long base, unsigned long long exp, int mod )
{
	int mul[ 64 ] = { base % mod }, ans = 1;
	for( int i = 1; i < 64; ++i )
		mul[ i ] = mul[ i - 1 ] * mul[ i - 1 ] % mod;
	for( int i = 0; i < 64; ++i )
		if( exp & 1ull << i )
			ans = ans * mul[ i ] % mod;
	return ans;
}

int main()
{
	int t;
	unsigned long long base, exp, mod;

	for( cin >> t; t-- && cin >> base >> exp >> mod; )
	{
		vector<int> cycle( 1, 0 );
		int size = 2;
		cycle.push_back( 1 );

		while( ( cycle[ size - 1 ] + cycle[ size - 2 ] ) % mod || cycle[ size - 1 ] != 1 )
			cycle.push_back( ( cycle[ size - 1 ] + cycle[ size - 2 ] ) % mod ), ++size;
		cout << ( mod == 1? 0 : cycle[ big_mod( base, exp, size ) ] ) << endl;
	}
}
