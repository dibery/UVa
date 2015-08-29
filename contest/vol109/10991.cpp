#include<cstdio>
#include<cmath>

int main()
{
	int t;
	double r[ 3 ], area;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%lf %lf %lf", r, r + 1, r + 2 );

		double a = r[ 0 ] + r[ 1 ], b = r[ 1 ] + r[ 2 ], c = r[ 2 ] + r[ 0 ], s = ( a+b+c ) / 2; // Tri ABC
		double cc = ( a*a + b*b - c*c ) / ( 2*a*b ), cb = ( a*a + c*c - b*b ) / ( 2*a*c ), ca = ( b*b + c*c - a*a ) / ( 2*b*c ); // cosine value
		double A = acos( ca ), B = acos( cb ), C = acos( cc ); // Angle ABC

		area = sqrt( s * ( s-a ) * ( s-b ) * ( s-c ) );
		printf( "%f\n", area - r[ 0 ] * r[ 0 ] * B / 2 - r[ 1 ] * r[ 1 ] * C / 2 - r[ 2 ] * r[ 2 ] * A / 2 );
	}
}
