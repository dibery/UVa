#include<iostream>
#include<algorithm>
using namespace std;

int primes[ 9999 ] = { 2 }, size = 1;

bool isprime( int n )
{
	for( int i = 0; primes[ i ] * primes[ i ] <= n; ++i )
		if( n % primes[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < 1e5; i += 2 )
		if( isprime( i ) )
			primes[ size++ ] = i;
	for( int area, up, down; cin >> area >> up >> down && area; )
	{
		int max_area = 0, U, D;
		for( int i = 0; primes[ i ] * 2 <= area; ++i )
		{
			int *p = upper_bound( primes, primes + i + 1, area / primes[ i ] ) - 1;
			if( primes[ i ] * *p >= max_area && *p * down >= primes[ i ] * up )
			{
				max_area = primes[ i ] * *p;
				U = *p;
				D = primes[ i ];
			}
		}
		cout << U << ' ' << D << endl;
	}
}
