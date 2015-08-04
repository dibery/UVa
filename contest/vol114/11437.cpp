#include<cstdio>
#include<cmath>
inline double area( double a, double b, double c )
{
    double s = ( a+b+c ) / 2;
    return sqrt( s * (s-a) * (s-b) * (s-c) );
}

int main()
{
    int t;
    double ax, ay, bx, by, cx, cy, dx, dy, ex, ey, fx, fy;

    for( scanf( "%d", &t ); t; --t )
    {
        scanf( "%lf %lf %lf %lf %lf %lf", &ax, &ay, &bx, &by, &cx, &cy );
        dx = 2.0 / 3 * bx + 1.0 / 3 * cx, dy = 2.0 / 3 * by + 1.0 / 3 * cy;
        ex = 2.0 / 3 * cx + 1.0 / 3 * ax, ey = 2.0 / 3 * cy + 1.0 / 3 * ay;
        fx = 2.0 / 3 * ax + 1.0 / 3 * bx, fy = 2.0 / 3 * ay + 1.0 / 3 * by;
        printf( "%.0f\n", area( hypot( ax-dx, ay-dy ), hypot( bx-ex, by-ey ), hypot( cx-fx, cy-fy ) ) * 9 / 49 );
    }
}
