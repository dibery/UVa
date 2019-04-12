#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;
const int N = 205;

int main()
{
	for( char sa[ N ], sb[ N ]; gets( sa ) && gets( sb ); )
	{
		int a[ N ] = { 0 }, b[ N ] = { 0 }, la = 0, lb = 0, ans;

		while( sa[ la ] )
			a[ la ] = sa[ la++ ] - '0';
		while( sb[ lb ] )
			b[ lb ] = sb[ lb++ ] - '0';
		ans = la + lb;

		for( int i = 0, j; i < lb && ans > max( la + i, lb ); ++i ) // i is offset
		{
			for( j = 0; j < min( la + i, lb ) && a[ j ] + b[ i + j ] <= 3; ++j );
			if( j == min( la + i, lb ) )
				ans = min( ans, max( la + i, lb ) );
		}
		for( int i = 0, j; i < la && ans > max( lb + i, la ); ++i ) // i = offset
		{
			for( j = 0; j < min( lb + i, la ) && a[ i + j ] + b[ j ] <= 3; ++j );
			if( j == min( lb + i, la ) )
				ans = min( ans, max( lb + i, la ) );
		}

		printf( "%d\n", ans );
	}
}
