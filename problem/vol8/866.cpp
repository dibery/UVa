#include<bits/stdc++.h>
using namespace std;

struct line
{
	int x1, y1, x2, y2, dx, dy, A, B, C; // Ax+By=C
	line()
	{
		scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
		if( x1 > x2 || x1 == x2 && y1 > y2 )
			swap( x1, x2 ), swap( y1, y2 );
		dx = x2 - x1;
		dy = y2 - y1;
		A = -dy;
		B = dx;
		C = A*x1 + B*y1;
	}
	bool insersect( const line& L )
	{
		int D = A*L.B - B*L.A, Dx = C*L.B - B*L.C, Dy = A*L.C - C*L.A;
		if( D < 0 )
			D = -D, Dx = -Dx, Dy = -Dy;
		if( !D )
			return false;
		else
			return in( Dx, D*x2, D*x1 ) && in( Dy, D*y2, D*y1 ) && in( Dx, D*L.x2, D*L.x1 ) && in( Dy, D*L.y2, D*L.y1 );
	}
	bool in( int a, int b, int c ) { return a >= min( b, c ) && a <= max( b, c ); }
};

int main()
{
	int t, size;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d", &size );
		line all[ size ];
		int cross = 0;

		for( int i = 0; i < size; ++i )
			for( int j = 0; j < size; ++j )
				cross += all[ i ].insersect( all[ j ] );
		printf( "%d\n", cross + size );
		if( t )
			puts( "" );
	}
}
