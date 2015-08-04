#include<bits/stdc++.h>
using namespace std;

inline int sigma( int a0, int d, int n )
{
	int an = a0 + (n-1) * d;
	if( an >= 0 || !n )
		return ( a0 + an ) * n / 2;
	an = a0 + ( ( n = a0 / -d + 1 ) - 1 ) * d;
	return ( a0 + an ) * n / 2;
}

int main()
{
	int lake, time;
	bool first = true;

	while( scanf( "%d %d", &lake, &time ) && lake )
	{
		int ans[ 961 ][ 26 ] = { { 0 } }, spend[ 961 ][ 25 ] = { 0 }, init[ 25 ] = { 0 }, down[ 25 ] = { 0 }, next[ 25 ] = { 0 };

		time *= 60;
		for( int i = 0; i < lake; ++i )
			scanf( "%d", init+i );
		for( int i = 0; i < lake; ++i )
			scanf( "%d", down+i );
		for( int i = 0; i < lake-1; ++i )
			scanf( "%d", next+i ), next[ i ] *= 5;

		for( int i = lake-1; i >= 0; --i )
			for( int t = 0; t <= time; t += 5 )
				for( int This = 0; This <= t; This += 5 )
					if( ( t >= This + next[ i ] || t == This ) && ans[ t ][ i ] <= sigma( init[ i ], -down[ i ], This / 5 ) + ans[ max( t - This - next[ i ], 0 ) ][ i+1 ] )
						ans[ t ][ i ] = sigma( init[ i ], -down[ i ], This / 5 ) + ans[ max( t - This - next[ i ], 0 ) ][ i+1 ], spend[ t ][ i ] = This;

		if( !first )
			puts( "" );
		else
			first = false;

		for( int i = 0, t = time; i < lake; t -= t <= 0? 0 : spend[ t ][ i ] + next[ i ], ++i )
			printf( "%d%s", t <= 0? 0 : spend[ t ][ i ], i == lake-1? "\n" : ", " );
		printf( "Number of fish expected: %d\n", *ans[ time ] );
	}
}
