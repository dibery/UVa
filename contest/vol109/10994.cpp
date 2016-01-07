#include<cstdio>

long long calc( long long low, long long high )
{
	long long sum = 0;

	if( high < 10 )
		return ( low + high ) * ( high - low + 1 ) / 2;
	if( low % 10 > 1 )
		sum += ( low % 10 + 9 ) * ( 9 - low % 10 + 1 ) / 2;
	if( high % 10 < 9 && high % 10 )
		sum += ( high % 10 ) * ( high % 10 + 1 ) / 2;
	sum += 45ll * ( ( high + 1 ) / 10 - ( low + 8 ) / 10 );
	sum += calc( ( low + ( low % 10? 10 - low % 10 : 0 ) ) / 10, high / 10 );

	return sum;
}

int main()
{
	for( int l, h; scanf( "%d %d", &l, &h ) && l >= 0; )
		printf( "%lld\n", calc( l, h ) );
}
