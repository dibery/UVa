#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;

const long double F = 5, phi = ( 1 + sqrt( F ) ) / 2;
vector<int> prime;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

long long fib( int index )
{
	long double tmp = log10( phi ) * index - log10( sqrt( F ) );
	if( tmp >= 9 )
		tmp -= int( tmp ) - 8;
	else
		return round( pow( 10, tmp ) );
	return ( long long ) trunc( pow( 10, tmp ) );
}

int main()
{
	prime.push_back( 2 );
	prime.push_back( 2 );
	for( int i = 3; prime.size() <= 22000; i += 2 )
		if( isp( i ) )
			prime.push_back( i );
	for( int n; scanf( "%d", &n ) == 1; )
		printf( "%lld\n", fib( prime[ n ] + ( n <= 2 ) ) );
}
