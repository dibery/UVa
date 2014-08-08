#include<cstdio>
#include<cmath>
const double PI = acos(-1);

int main()
{
	double n, r1 = sqrt(3)/2, r3 = r1/2, r2 = sqrt(3)*tan(PI/12), r4 = (6*sqrt(7) - 7*sqrt(3)) / 10;

	while( scanf( "%lf", &n ) == 1 )
		printf( "%.10lf %.10lf %.10lf %.10lf\n", n*r1, n*r2, n*r3, n*r4 );
}
