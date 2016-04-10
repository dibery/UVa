#include<cstdio>
#include<climits>
#include<algorithm>

int main()
{
	for( unsigned N, a, b, c, d; scanf( "%u", &N ) == 1; )
	{
		unsigned ip[ 1000 ] = { 0 }, mask = UINT_MAX;

		for( int i = 0; i < N && scanf( "%u.%u.%u.%u", &a, &b, &c, &d ); ++i )
			ip[ i ] = ( a << 24 ) + ( b << 16 ) + ( c << 8 ) + d;
		while( !std::all_of( ip, ip + N, [ ip, mask ]( unsigned i ) { return ( i & mask ) == ( *ip & mask ); } ) )
			mask ^= mask & -mask;
		*ip &= mask;
		printf( "%d.%d.%d.%d\n", *ip >> 24, *ip >> 16 & 255, *ip >> 8 & 255, *ip & 255 );
		printf( "%d.%d.%d.%d\n", mask >> 24, mask >> 16 & 255, mask >> 8 & 255, mask & 255 );
	}
}
