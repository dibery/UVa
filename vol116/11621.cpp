#include<bits/stdc++.h>
using namespace std;

int main()
{
	typedef long long ll;
	set<ll> fft;

	for( ll i = 1; i < UINT_MAX; i *= 2 )
		for( ll j = i; j < UINT_MAX; j *= 3 )
			fft.insert( j );

	for( ll n; cin >> n && n; cout << *fft.lower_bound( n ) << endl );
}
