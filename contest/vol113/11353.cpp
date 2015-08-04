#include<cstdio>
#include<algorithm>
using namespace std;

int prime[ 225 ] = { 2 }, size = 1, qnt[ 2000001 ] = { 0, 1 };

class node
{
	public:
		node( int t = 0, int n = 0 ) { time = t; num = n; }
		bool operator< (const node& rhs) const { return time != rhs.time? time < rhs.time : num < rhs.num; }
		int time, num;
} all[ 2000000 ];

bool check( int n )
{
	for( int i = 0; i < size && prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	int n, t = 0;

	for( int i = 3; i*i <= 2000000; i += 2 )
		if( check( i ) )
			prime[ size++ ] = i;
	for( int i = 2; i <= 2000000; ++i )
		if( !qnt[ i ] )
			for( long long int j = i; j <= 2000000; j *= i )
				for( int k = j; k <= 2000000; k += j )
					++qnt[ k ];
	for( int i = 0; i < 2000000; ++i )
		all[ i ] = node( qnt[ i+1 ], i+1 );
	sort( all, all+2000000 );

	while( scanf( "%d", &n ) &&n )
		printf( "Case %d: %d\n", ++t, all[ n-1 ].num );
}
