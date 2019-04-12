#include<cstdio>
#include<cmath>
#define mod 100000007

inline long long sqr( long long n ) { return n*n; }

int main()
{
	for( long long n; scanf( "%lld", &n ) && n; puts( "" ) )
	{
		bool out = false;
		for( long long r = 1; r*r*6 < n; ++r )
			if( ( n - 6*r*r ) % ( 7*r ) == 0 )
				out = true, printf( "Possible Missing Soldiers = %lld\n", sqr( ( n - 6*r*r ) / r / 7 % mod ) * 2 % mod );
		if( !out )
			puts( "No Solution Possible" );
	}
}
