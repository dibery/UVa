#include<bits/stdc++.h>
using namespace std;

long long f( long long n )
{
	if( n < 10 )
		return 0;

	long long int ret = n / 10;
	for( long long scale = 10; scale * 10 <= n; scale *= 10 )
		if( scale * 100 > n ) // Last digit to use
			ret += ( n / scale / 10 - 1 ) * scale + min( scale, n % ( scale * 10 ) + 1 );
		else
			ret += ( n / scale / 10 - ( n / scale % 10 < 1 ) ) * scale + ( n / scale % 10 >= 1? 0 : min( scale, n % scale + 1 ) );
	return ret;
}

int main()
{
	for( long long begin, end; scanf( "%lld %lld", &begin, &end ) && begin >= 0; )
		printf( "%lld\n", f( end ) - f( begin-1 ) + ( begin == 0 ) );
}
