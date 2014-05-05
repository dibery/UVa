#include<cstdio>
#include<cmath>

int main()
{
    double a, b, c, s, scale = 4/3.0, ans;

    while( scanf( "%lf %lf %lf", &a, &b, &c ) != EOF )
        s = ( a+b+c ) / 2, printf( "%.3f\n", ( ans = sqrt( s * ( s-a ) * ( s-b ) * ( s-c ) ) * scale ) > 0 ? ans : -1 );

	return 0;
}