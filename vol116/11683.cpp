#include<cstdio>

int main()
{
	int h, w, goal[ 10001 ] = { 0 };

	while( scanf( "%d %d", &h, &w ) && h+w )
	{
		int cut = 0;
		for( int i = 1; i <= w; ++i )
			scanf( "%d", goal+i );
		*goal = h;
		for( int j = 1; j <= w; ++j )
			if( goal[ j-1 ] > goal[ j ] )
				cut += goal[ j-1 ] - goal[ j ];
		printf( "%d\n", cut );
	}
}
