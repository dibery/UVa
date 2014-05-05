#include<cstdio>
#include<cmath>
inline double sq( double n ) { return n*n; }
inline double abs( double n ) { return n < 0? -n : n; }
double ax, ay, bx, by, cx, cy, x, y, r;
char sign[ 2 ] = { '+', '-' };
void sol( double a, double b, double c, double d, double e, double f )
{
	x = ( c * e - b * f ) / ( a * e - b * d );
	y = ( a * f - c * d ) / ( a * e - b * d );
	r = sqrt( sq( x - ax ) + sq( y - ay ) );
}

int main()
{
	while( scanf( "%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy ) != EOF )
	{
		sol( 2*(bx-ax), 2*(by-ay), sq(bx)+sq(by)-sq(ax)-sq(ay), 2*(cx-ax), 2*(cy-ay), sq(cx)+sq(cy)-sq(ax)-sq(ay) );
		if( x > 0 )
			if( y > 0 )
				printf( "(x - %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n", x, y, r );
			else if( y == 0 )
				printf( "(x - %.3lf)^2 + y^2 = %.3lf^2\n", x, r );
			else
				printf( "(x - %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n", x, -y, r );
		else if( x == 0 )
			if( y > 0 )
				printf( "x^2 + (y - %.3lf)^2 = %.3lf^2\n", y, r );
			else if( y == 0 )
				printf( "x^2 + y^2 = %.3lf^2\n", r );
			else
				printf( "x^2 + (y + %.3lf)^2 = %.3lf^2\n", -y, r );
		else//
			if( y > 0 )
				printf( "(x + %.3lf)^2 + (y - %.3lf)^2 = %.3lf^2\n", -x, y, r );
			else if( y == 0 )
				printf( "(x + %.3lf)^2 + y^2 = %.3lf^2\n", -x, r );
			else
				printf( "(x + %.3lf)^2 + (y + %.3lf)^2 = %.3lf^2\n", -x, -y, r );
        if( x )
            if( y )
                if( sq( x ) + sq( y ) - sq( r ) )
                    printf( "x^2 + y^2 %c %.3fx %c %.3fy %c %.3f = 0\n\n", sign[ x > 0 ], abs( 2*x ), sign[ y > 0 ], abs( 2*y ), sign[ sq( x ) + sq( y ) - sq( r ) < 0 ], abs( sq( x ) + sq( y ) - sq( r ) ) );
                else
                    printf( "x^2 + y^2 %c %.3fx %c %.3fy = 0\n\n", sign[ x > 0 ], abs( 2*x ), sign[ y > 0 ], abs( 2*y ) );
            else//
                if( sq( x ) + sq( y ) - sq( r ) )
                    printf( "x^2 + y^2 %c %.3fx %c %.3f = 0\n\n", sign[ x > 0 ], abs( 2*x ), sign[ sq( x ) + sq( y ) - sq( r ) < 0 ], abs( sq( x ) + sq( y ) - sq( r ) ) );
                else
                    printf( "x^2 + y^2 %c %.3fx = 0\n\n", sign[ x > 0 ], abs( 2*x ) );
        else//
            if( y )
                if( sq( x ) + sq( y ) - sq( r ) )
                    printf( "x^2 + y^2 %c %.3fy %c %.3f = 0\n\n", sign[ y > 0 ], abs( 2*y ), sign[ sq( x ) + sq( y ) - sq( r ) < 0 ], abs( sq( x ) + sq( y ) - sq( r ) ) );
                else
                    printf( "x^2 + y^2 %c %.3fy = 0\n\n", sign[ y > 0 ], abs( 2*y ) );
            else//
                if( sq( x ) + sq( y ) - sq( r ) )
                    printf( "x^2 + y^2 %c %.3f = 0\n\n", sign[ sq( x ) + sq( y ) - sq( r ) < 0 ], abs( sq( x ) + sq( y ) - sq( r ) ) );
                else
                    printf( "x^2 + y^2 = 0\n\n" );
	}

	return 0;
}
