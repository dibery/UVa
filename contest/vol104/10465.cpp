#include<cstdio>
#include<climits>
#include<algorithm>

int main()
{
	int a, b, time;

	while( scanf( "%d %d %d", &a, &b, &time ) == 3 )
	{
		int burger = 0, r = INT_MAX;
		if( a < b )
			std::swap( a, b );
		for( int big = 0; a * big <= time && r; ++big )
			if( time - a * big - ( time - a * big ) / b * b < r )
			{
				r = time - a * big - ( time - a * big ) / b * b;
				burger = big + ( time - a * big ) / b;
			}
		if( !r )
			printf( "%d\n", burger );
		else
			printf( "%d %d\n", burger, r );
	}
}
