#include<cstdio>
#include<cmath>
#include<set>
using namespace std;
bool judge( int n )
{
	for( int i = 3; i*i <= n; i += 2 )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	set<unsigned long long int> all;
	all.insert( 1 );
	double LIMIT = log( 2 ) * 64;
	bool isprime[ 65 ] = { false, false, true };
	for( int i = 3; i <= 64; i += 2 )
		isprime[ i ] = judge( i );

	for( unsigned long long int i = 2; i <= 65536; ++i )
		if( all.find( i ) == all.end() )
			for( int expo = 4; log( i ) * expo < LIMIT; ++expo )
				if( !isprime[ expo ] )
					all.insert( (unsigned long long int) ( pow( (long double)i, expo ) + 1e-1 ) );
	for( set<unsigned long long int>::iterator it = all.begin(); it != all.end(); ++it )
		printf( "%llu\n", *it );
}
