#include<cstdio>

int main()
{
	int t, x1, x2, x3, x4, y1, y2, y3, y4;

	puts( "INTERSECTING LINES OUTPUT" );
	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4 );
		int a = y1-y2, b = x2-x1, c = a*x1 + b*y1, A = y3-y4, B = x4-x3, C = A*x3 + B*y3;	//ax+by=c Ax+By=C
		double d = a*B - b*A, dx = c*B - b*C, dy = a*C - c*A;
		if( d )
			printf( "POINT %.2f %.2f\n", dx/d, dy/d );
		else
			puts( dx || dy? "NONE" : "LINE" );
	}
	puts( "END OF OUTPUT" );
}
