#include<cstdio>
#include<cstdlib>
#include<cmath>
const double eps = 1e-12;

int main()
{
	double size, pos;

	while( scanf( "%lf %lf", &size, &pos ) && size + pos )
	{
		int layer = ceil( sqrt( pos ) ), center = size / 2 + 1;
		if( layer % 2 == 0 )
			if( layer * layer - layer >= pos )
				printf( "Line = %d, column = %.0f.\n", center + layer / 2, center - layer / 2 + ( layer * layer - layer + 1 - pos ) );
			else
				printf( "Line = %.0f, column = %d.\n", center - layer / 2 + 1 + ( layer * layer - pos ), center - layer / 2 );
		else//
			if( layer * layer - layer >= pos )
				printf( "Line = %d, column = %.0f.\n", center - layer / 2, center + layer / 2 - ( layer * layer - layer + 1 - pos ) );
			else
				printf( "Line = %.0f, column = %d.\n", center + layer / 2 - ( layer * layer - pos ), center + layer / 2 );
	}
}
