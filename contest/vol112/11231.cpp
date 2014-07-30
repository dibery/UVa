#include<cstdio>

int main()
{
	int r, c, white;

	while( scanf( "%d %d %d", &r, &c, &white ) && r + c + white )
		if( white )
			printf( "%d\n", ((r-6) / 2) * ((c-6) / 2) + ((r-7) / 2) * ((c-7) / 2 ) );
		else
			printf( "%d\n", ((r-6) / 2) * ((c-7) / 2) + ((r-7) / 2) * ((c-6) / 2 ) );
}