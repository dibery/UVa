#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll S = 81, N = 1000000000000000000ll;
const double LIM = 18.00001;

ll fib[] = { 2, 3, 5 }, fib2[ S ] = { 13, 21 };
double logfib[ S ];
set<ll> S1, S2;

void bt2( int p = 0, ll prod = 1, double logval = 0 )
{
	if( logval <= LIM )
		if( p == S )
			S2.insert( prod );
		else
			for( ; logval < LIM; prod *= fib2[ p ], logval += logfib[ p ] )
				bt2( p + 1, prod, logval );
}

void bt( int p = 0, ll prod = 1, double logval = 0 )
{
	if( logval > LIM )
		return;
	if( p == 3 )
		S1.insert( prod );
	else
		for( ; logval < LIM; prod *= fib[ p ], logval += log10( fib[ p ] ) )
			bt( p + 1, prod, logval );
}

int main()
{
	for( int i = 2; i < S; ++i )
		fib2[ i ] = fib2[ i - 1 ] + fib2[ i - 2 ];
	for( int i = 0; i < S; ++i )
		logfib[ i ] = log10( fib2[ i ] );
	bt();
	bt2();
	vector<ll> V1( S1.begin(), S1.end() ), V2( S2.begin(), S2.end() );

	int t;
	ll low, high;
	for( cin >> t; t-- && cin >> low >> high; )
	{
		ll ans = -1;
		for( auto i: V1 )
		{
			if( i > high )
				break;
			if( i >= low && i <= high && i > ans )
				ans = i;
			auto n = *--upper_bound( V2.begin(), V2.end(), high / i );
			if( i * n >= low && i * n <= high && i * n > ans )
				ans = i * n;
		}
		printf( "%lld\n", ans );
	}
}
