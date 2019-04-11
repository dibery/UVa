#include<bits/stdc++.h>
using namespace std;

set<unsigned long long> seldon;

void fill( int one, int zero )
{
	for( char n[ 200 ] = { 0 }, len = 0; !n[ 63 ]; )
	{
		for( int i = 0; i < one; ++i )
			n[ len++ ] = '1';
		if( n[ 63 ] )
			break;
		seldon.insert( strtoll( n, NULL, 2 ) );
		for( int i = 0; i < zero; ++i )
			n[ len++ ] = '0';
		if( !n[ 63 ] )
			seldon.insert( strtoll( n, NULL, 2 ) );
	}
}

int main()
{
	for( int one = 1; one <= 63; ++one )
		for( int zero = 0; one + zero <= 63; ++zero )
			fill( one, zero );

	for( unsigned long long low, high; cin >> low >> high; )
		cout << distance( seldon.lower_bound( low ), seldon.upper_bound( high ) ) << endl;
}
