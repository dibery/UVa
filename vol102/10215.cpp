#include<cstdio>
#include<cmath>
#include<algorithm>

int main()
{
    double a, b;

    while( scanf( "%lf %lf", &a, &b ) == 2 )
        printf( "%.3f 0.000 %.3f\n", ( (a+b) - sqrt( a*a + b*b - a*b ) ) / 6 + 1e-9, std::min( a, b ) / 2 + 1e-9 );

	return 0;
}