#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

int main()
{
	int t, size;

	for( scanf( "%d", &t ); t--; )
	{
		double x = 0, y = 0;
		bool sym = true;
		scanf( "%d", &size );
		pair<int,int> point[ size ];

		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d", &point[ i ].x, &point[ i ].y );
			x += point[ i ].x;
			y += point[ i ].y;
		}
		x /= size;
		y /= size;
		sort( point, point+size );

		for( int i = 0; i < size && sym; ++i )
		{
			pair<int,int> match = make_pair( 2*x - point[ i ].x, 2*y - point[ i ].y );
			sym &= *lower_bound( point, point+size, match ) == match;
		}
		puts( sym? "yes" : "no" );
	}
}
