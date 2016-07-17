#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int N = 2000000100;
vector<bool> notprime( N, false );
int primes[ N / 10 ], size, t, a, b, k, s;

int main()
{
	notprime[ 1 ] = true;
	primes[ size++ ] = 2;

	for( int i = 3; i * i < N; i += 2 )
		if( !notprime[ i ] )
			for( int j = i * i; j < N; j += 2 * i )
				notprime[ j ] = true;
	for( int i = 3; i < N; i += 2 )
		if( !notprime[ i ] )
			primes[ size++ ] = i;

	for( cin >> t; t-- && cin >> a >> b >> k >> s; )
	{
		int ans = 0;
		for( int *p = lower_bound( primes, primes + size, a ); *( p + k - 1 ) <= b; ++p )
			ans += *( p + k - 1 ) - *p == s;
		cout << ans << endl;
	}
}
