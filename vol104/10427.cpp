#include<cstdio>
#include<cstring>

char s[ 100000010 ], *p = s;

int main()
{
	for( int i = 1; p - s < 100000000; p += strlen( p ), ++i )
		sprintf( p, "%d", i );
	for( int i; scanf( "%d", &i ) == 1; printf( "%c\n", s[ i-1 ] ) );
}
