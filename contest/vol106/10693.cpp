#include<cstdio>
#include<cmath>

int main()
{
	for( int L, f; scanf( "%d %d", &L, &f ) && L; )
	{
		double v = sqrt( 2. * L * f );
		printf( "%.8f %.8f\n", v, v * 1800 / L );
	}
}
