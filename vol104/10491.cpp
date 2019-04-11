#include<cstdio>
#define all (cow+car)

int main()
{
	for( double cow, car, show; scanf( "%lf %lf %lf", &cow, &car, &show ) == 3; )
		printf( "%.5f\n", cow / all * car / ( all - show - 1 ) + car / all * ( car - 1 ) / ( all - show - 1 ) );
}
