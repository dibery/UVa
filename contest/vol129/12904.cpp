#include<bits/stdc++.h>
using namespace std;

double calc( int S[], int student, int a, int b, int c )
{
	double ave = student / 4.0, dist = 0;
	int have[ 4 ] = { S[ a ], S[ b ] - S[ a ], S[ c ] - S[ b ], S[ 160 ] - S[ c ] };

	for( int i = 0; i < 4; ++i )
		dist += abs( have[ i ] - ave );
	return dist;
}

int main()
{
	int t, student, score;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int credit[ 161 ] = { 0 }, sum[ 161 ] = { 0 }, a, b, c;
		double diff = INT_MAX, tmp;

		scanf( "%d", &student );
		for( int i = 0; i < student; ++i )
			scanf( "%d", &score ), ++credit[ score ];
		*sum = *credit;
		for( int i = 1; i <= 160; ++i )
			sum[ i ] = sum[ i-1 ] + credit[ i ];
		for( int i = 0; i < 160; ++i )
			for( int j = i+1; j < 160; ++j )
				for( int k = j+1; k < 160; ++k )
					if( ( tmp = calc( sum, student, i, j, k ) ) < diff )
						diff = tmp, a = i, b = j, c = k;
		printf( "Case %d: %d %d %d\n", n, a, b, c );
	}
}
