#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool isprime( ll );
ll pollard( ll, ll ), gcd( ll, ll ), f( ll, ll, ll, ll = 0 ), pow( ll, ll, ll );
ll gcd( ll a, ll b ) { return a % b? gcd( b, a % b ) : b; }
void dec( ll );
map<ll,int> factor;

int main()
{
	ll n, t;

	for( scanf( "%lld", &t ); t--; factor.clear() )
	{
		scanf( "%lld", &n );
		printf( "%lld = ", n );

		while( ~n & 1 )
			n >>= 1, ++factor[ 2 ];
		dec( n );

		for( map<ll,int>::iterator i = factor.begin(); i != factor.end(); printf( ++i == factor.end()? "\n" : " * " ) )
			printf( i->second > 1? "%lld^%d" : "%lld", i->first, i->second );
	}
}

void dec( ll n )
{
	if( n == 1 )
		return;
	else if( isprime( n ) )
		++factor[ n ];
	else
	{
		ll d = n;
		for( int i = 2; d == n; ++i )
			d = pollard( n, i );
		dec( d );
		dec( n / d );
	}
}

bool isprime( ll n )
{
	if( n == 2 )
		return true;
	else if( n < 2 || n % 2 == 0 )
		return false;
	else
	{
		ll u = n-1, t = 0, test[] = { 75088 % n, 642735 % n, 203659041 % n };

		while( ~u & 1 )
			u >>= 1, ++t;
		for( int i = 0; i < 3; ++i )
			if( test[ i ] > 1 && test[ i ] < n-1 )
			{
				ll x = pow( test[ i ], u, n );
				if( x == 1 || x == n-1 )
					continue;

				for( int i = 1; i < t && x != n-1; ++i )
					if( ( x = f( x, x, n ) ) == 1 )
						return false;
				if( x != n-1 )
					return false;
			}
	}
	return true;
}

ll pow( ll b, ll e, ll m ) // b^e % m
{
	ll res[ 60 ] = { b % m }, ans = 1;

	for( int i = 1; i < 60; ++i )
		res[ i ] = f( res[ i-1 ], res[ i-1 ], m );
	for( int i = 0; i < 60 && e >= 1ll << i; ++i )
		if( e & 1ll << i )
			ans = f( ans, res[ i ], m );
	return ans;
}

ll pollard( ll n, ll c )
{
	for( ll x = 2, y = 2, d; ; )
	{
		x = f( x, x, n, c );
		y = f( y, y, n, c );
		y = f( y, y, n, c );
		d = gcd( max( x, y ) - min( x, y ), n );
		if( d > 1 && d <= n )
			return d;
	}
}

ll f( ll x, ll y, ll m, ll offset ) // x*y+offset % m
{
	ll ans = 0, res[ 60 ] = { x };

	for( int i = 1; i < 60; ++i )
		res[ i ] = res[ i-1 ] * 2 % m;
	for( int i = 0; i < 60 && y >= 1ll << i; ++i )
		if( y & 1ll << i )
			ans += res[ i ];
	return ( ans + offset ) % m;
}
