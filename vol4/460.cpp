#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int t, x1, x2, x3, x4, y1, y2, y3, y4;

	for( scanf( "%d", &t ); t; printf( --t? "\n" : "" ) )
	{
		scanf( "%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );
		if( y3 >= y2 || x3 >= x2 )
			puts( "No Overlap" );
		else if( x3 < x1 )
			if( y3 >= y1 )
				if( x4 <= x1 )
					puts( "No Overlap" );
				else
					printf( "%d %d %d %d\n", x1, y3, min( x2, x4 ), min( y2, y4 ) );
			else
				if( x4 <= x1 || y4 <= y1 )
					puts( "No Overlap" );
				else
					printf( "%d %d %d %d\n", x1, y1, min( x2, x4 ), min( y2, y4 ) );
		else
			if( y3 >= y1 )
				printf( "%d %d %d %d\n", x3, y3, min( x2, x4 ), min( y2, y4 ) );
			else
				if( y4 <= y1 )
					puts( "No Overlap" );
				else
					printf( "%d %d %d %d\n", x3, y1, min( x2, x4 ), min( y2, y4 ) );
	}
}
