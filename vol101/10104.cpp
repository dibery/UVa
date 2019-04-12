#include<cstdio>
void gcd( int a, int b, int& factor, int& x, int& y )
{
	if( b == 0 )
	{
		factor = a;
		x = 1;
		y = 0;
	}
	else
	{
		gcd( b, a%b, factor, y, x );
		y -= a / b * x;
	}
}

int main()
{
	int a, b, factor, x, y;

	while( scanf( "%d %d", &a, &b ) == 2 )
	{
		gcd( a, b, factor, x, y );
		printf( "%d %d %d\n", x, y, factor );
	}
}
