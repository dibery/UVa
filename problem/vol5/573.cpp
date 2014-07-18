#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int h, climb, drop;
	double tire;

	while( scanf( "%d %d %d %lf", &h, &climb, &drop, &tire ) && h )
	{
		double table[ 1000 ][ 4 ] = { 0 }, down = tire / 100 * climb;
		int day = 0;

		tire /= 100;
		do
		{
			if( day != 0 )
				table[ day ][ 0 ] = table[ day-1 ][ 3 ];
			table[ day ][ 1 ] = max( climb - day * down, 0.0 );
			table[ day ][ 2 ] = table[ day ][ 1 ] + table[ day ][ 0 ];
			table[ day ][ 3 ] = table[ day ][ 2 ] - drop;
		}
		while( table[ day ][ 2 ] <= h && table[ day ][ 3 ] >= 0 && ++day );

		if( table[ day ][ 2 ] <= h )
			printf( "failure on day %d\n", day+1 );
		else
			printf( "success on day %d\n", day+1 );
	}
}
