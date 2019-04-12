#include<bits/stdc++.h>
using namespace std;

vector<int> primes{ 1, 2 };

bool isprime( int n )
{
	for( int i: primes )
		if( n % i == 0 && i > 1 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; primes.size() < 100; i += 2 )
		if( isprime( i ) )
			primes.push_back( i );
	
	int t, size, score;

	for( cin >> t; t-- && cin >> size >> score; )
	{
		vector<int> ans( score + 1, INT_MAX );

		ans[ 0 ] = 0;
		for( int i = 1; i <= score; ++i )
			for( int j = 0; j < size && primes[ j ] <= i; ++j )
				ans[ i ] = min( ans[ i ], 1 + ans[ i - primes[ j ] ] );
		cout << ans[ score ] << endl;
	}
}
