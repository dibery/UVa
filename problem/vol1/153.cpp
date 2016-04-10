#include<bits/stdc++.h>
using namespace std;

int all_perm( vector<int> v, int now )
{
	--v[ now ];
	int factor[ 31 ] = { 0 }, size = accumulate( v.begin(), v.end(), 0 ), ans = 1;

	for( int i = 2, j = 2; i <= size; j = ++i )
		for( int k = 2; j > 1; ++k )
			while( j % k == 0 )
				j /= k, ++factor[ k ];
	for( int i = 0; i < 26; ++i )
		for( int j = 2, k = 2; j <= v[ i ]; k = ++j )
			for( int l = 2; k > 1; ++l )
				while( k % l == 0 )
					k /= l, --factor[ l ];
	for( int i = 0; i < 31; ++i )
		while( factor[ i ]-- )
			ans *= i;
	return ans;
}

int get_pos( string s )
{
	if( s.empty() )
		return 0;
	string tmp = s;
	vector<int> times( 26 );
	int ans = 0;

	sort( tmp.begin(), tmp.end() );
	for( char c: s )
		++times[ c - 'a' ];
	for( int i = 0; i < s[ 0 ] - 'a'; ++i )
		if( times[ i ] )
			ans += all_perm( times, i );
	ans += get_pos( s.substr( 1 ) );

	return ans;
}

int main()
{
	for( string s; cin >> s && s != "#"; )
		cout << setw( 10 ) << get_pos( s ) + 1 << endl;
}
