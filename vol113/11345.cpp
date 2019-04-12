#include<cstdio>

int main()
{
	int t, size, lx, ly, rx, ry, x, y, X, Y;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		bool wrong = false;
		scanf( "%d", &size );
		scanf( "%d %d %d %d", &lx, &ly, &rx, &ry );
		for( int i = 1; i < size; ++i )
		{
			scanf( "%d %d %d %d", &x, &y, &X, &Y );
			if( wrong )
				continue;
			if( x <= lx && y <= ly )
				if( X <= rx && X >= lx && Y <= ry && Y >= ly )
					rx = X, ry = Y;
				else if( X <= rx && X >= lx && Y >= ry )
					rx = X;
				else if( X >= rx && Y >= ly && Y <= ry )
					ry = Y;
				else if( X >= rx && Y >= ry );
				else
					wrong = true;
			else if( x <= lx && y >= ly && y <= ry )
				if( X >= lx && X <= rx && Y >= ly && Y <= ry )
					ly = y, ry = Y, rx = X;
				else if( X >= lx && X <= rx && Y >= ry )
					ly = y, rx = X;
				else if( X >= rx && Y >= ry )
					ly = y;
				else if( X >= rx && Y <= ry )
					ly = y, ry = Y;
				else if( X >= rx && Y >= ry );
				else
					wrong = true;
			else if( x >= lx && x <= rx && y >= ly && y <= ry )
				if( X <= rx && Y <= ry )
					lx = x, ly = y, rx = X, ry = Y;
				else if( X <= rx )
					lx = x, ly = y, rx = X;
				else if( Y >= ry )
					lx = x, ly = y;
				else
					lx = x, ly = y, ry = Y;
			else if( x >= lx && x <= rx && y <= ly )
				if( X <= rx && Y >= ly && Y <= ry )
					lx = x, rx = X, ry = Y;
				else if( X <= rx && Y >= ry )
					lx = x, rx = X;
				else if( X >= rx && Y >= ry )
					lx = x;
				else if( X >= rx && Y >= ly )
					lx = x, ry = Y;
				else
					wrong = true;
			else
				wrong = true;
			if( lx >= rx || ly >= ry || y == Y || x == X )
				wrong = true;
		}
		printf( "Case %d: %d\n", n, wrong? 0 : ( rx-lx ) * ( ry-ly ) );
	}
}
