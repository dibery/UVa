#include<bits/stdc++.h>
#define x first
#define y second
#define dy double( mount[ i+1 ].y - mount[ i ].y )
#define dx double( mount[ i+1 ].x - mount[ i ].x )
using namespace std;

int main()
{
	int t, size;
	pair<int,int> mount[ 100 ];

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d %d", &mount[ i ].x, &mount[ i ].y );
		sort( mount, mount + size, greater< pair<int,int> >() );

		int h = 0;
		double light = 0;

		for( int i = 0; i < size-1; ++i )
			if( mount[ i+1 ].y > mount[ i ].y && mount[ i+1 ].y > h )
			{
				double R = ( h - mount[ i ].y ) / dy, X = mount[ i ].x + R * dx, Y = mount[ i ].y + R * dy;
				light += hypot( X - mount[ i+1 ].x, Y - mount[ i+1 ].y );
				h = mount[ i+1 ].y;
			}
		printf( "%.2f\n", light );
	}
}
