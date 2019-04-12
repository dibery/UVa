#include<cstdio>

int main()
{
	int a, b, c, d, e;

	while( scanf( "%d %d %d %d %d", &a, &b, &c, &d, &e ) && a )
		printf( "%d\n", a*b*c*d*d*e*e );
}
