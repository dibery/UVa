#include<bits/stdc++.h>
using namespace std;

int main()
{
	pair<int,int> npos = make_pair( -1, -1 );
	int t, cap, tem, jar;
	double jcap[ 3000 ], jtem[ 3000 ];

	for( scanf( "%d", &t ); t-- && scanf( "%d %d %d", &cap, &tem, &jar ); )
	{
		for( int i = 0; i < jar; ++i )
			scanf( "%lf %lf", jcap + i, jtem + i );

		double best = INT_MIN;
		pair<int,int> ans = npos;

		for( int i = 0; i < jar; ++i )
		{
			double c = 0, h = 0; // capacity, heat
			for( int j = i; j < jar; ++j )
			{
				c += jcap[ j ];
				h += jtem[ j ] * jcap[ j ];
				if( c * 2 >= cap && c <= cap && h <= c * ( tem + 5 ) && abs( h - c * tem ) < c * abs( best - tem ) )
				{
					best = h / c;
					ans = make_pair( i, j );
				}
			}
		}

		if( ans == npos )
			puts( "Not possible" );
		else
			printf( "%d %d\n", ans.first, ans.second );
	}
}
