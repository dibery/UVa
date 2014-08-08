#include<cstdio>
#include<cmath>
const double PI = acos(-1);

int main()
{
	double a, b, c;

	while( scanf( "%lf %lf %lf", &a, &b, &c ) == 3 )
	{
		double semi = (a+b+c) / 2, tri = sqrt( semi * ( semi-a ) * ( semi-b ) * ( semi-c ) ), r = 2*tri / (a+b+c), in = r*r*PI, R = (a*b*c) / tri / 4, out = R*R*PI;
		printf( "%.4f %.4f %.4f\n", out - tri, tri - in, in );
	}
}
