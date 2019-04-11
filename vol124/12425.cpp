#include<bits/stdc++.h>
using namespace std;
typedef map<int,int> mii;
typedef map<long long,long long> mli;
typedef mli::iterator mlii;
typedef vector<long long> vll;

long long primes[ 100000 ] = { 2 }, size = 1;
mli phi, times;
bool isprime( int );
void gen( mlii, mlii, vll&, long long = 1 );
vll all_factor( long long );
long long get_phi( long long n );

int main()
{
	int t, q;
	long long n;

	for( int i = 3; i < 1000000; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;

	scanf( "%d", &t );
	for( int T = 1; T <= t; ++T )
	{
		scanf( "%lld %d", &n, &q );
		vll f = all_factor( n ), idv;

		printf( "Case %d\n", T );
		for( int i = 0; i < f.size(); ++i )
			idv.push_back( get_phi( n / f[ i ] ) );
		for( long long query; q-- && scanf( "%lld", &query ); )
		{
			long long ans = 0;
			if( query >= n )
				ans = n;
			else if( query <= 0 )
				ans = 0;
			else
				for( int i = 0; i < f.size() && query >= f[ i ]; ++i )
					ans += idv[ i ];
			printf( "%lld\n", ans );
		}
	}
}

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

vll all_factor( long long n )
{
	vll factors;
	times.clear();

	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		while( n % primes[ i ] == 0 )
			++times[ primes[ i ] ], n /= primes[ i ];
	if( n > 1 )
		++times[ n ];

	gen( times.begin(), times.end(), factors );
	sort( factors.begin(), factors.end() );

	return factors;
}

void gen( mlii begin, mlii end, vll& f, long long prod )
{
	if( begin == end )
		f.push_back( prod );
	else
		for( int i = 0; i <= begin->second; ++i, prod *= begin->first )
			gen( next( begin ), end, f, prod );
}

long long get_phi( long long n )
{
	if( phi.find( n ) != phi.end() )
		return phi[ n ];
	long long ans = n;
	for( auto& i: times )
		if( n % i.first == 0 )
			ans = ans / i.first * ( i.first - 1 );
	return phi[ n ] = ans;
}
