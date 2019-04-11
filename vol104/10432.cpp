#include<cstdio>
#include<cmath>
const double pi = 3.1415926535897932;

int main()
{
    double radius, polygon;

    while( scanf( "%lf %lf", &radius, &polygon ) != EOF )
        printf( "%.3lf\n", radius * radius * sin( 2 * pi / polygon ) / 2 * polygon + 1e-12 );

    return 0;
}
