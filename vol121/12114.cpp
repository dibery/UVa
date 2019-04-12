#include<cstdio>

int main()
{
	int b, s, t = 0;

	while( scanf( "%d %d", &b, &s ) && b )
		if( b == 1 )
			printf( "Case %d: :-\\\n", ++t );
		else if( b > s )
			printf( "Case %d: :-(\n", ++t );
		else
			printf( "Case %d: :-|\n", ++t );
}
