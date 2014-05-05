#include<cstdio>
#include<cmath>
const double pi = 3.14159265358979;
void transform( double &n )
{
    n = fmod( n, 360 );
    if( n > 180 )
        n = 360 - n;
}

int main()
{
    char type[ 4 ];
    double angle, radius;

    while( scanf( "%lf %lf %s", &radius, &angle, type ) == 3 )
    {
        radius += 6440;
        if( *type == 'm' )
           angle /= 60;
        transform( angle );
        printf( "%.6f %.6f\n", radius * pi * angle / 180, sqrt( radius*radius*2 - 2*radius*radius*cos( angle * pi / 180.0 ) ) );
    }

	return 0;
}