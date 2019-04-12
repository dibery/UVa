#include<cstdio>

int main()
{
	char *s[ 5 ] = { "0.00", "0.40", "0.20", "0.20", "0.40" };
	for( int i; scanf( "%d", &i ) && i; puts( s[ i % 5 ] ) );
}
