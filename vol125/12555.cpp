#include<cstdio>

int main()
{
	char in[ 30 ];
	int t, gin, lian, w, n = 0;

	for( scanf( "%d\n", &t ); t--; )
	{
		fgets( in, 30, stdin );
		w = sscanf( in, "%d %*[^0-9] %d %*s", &gin, &lian ) == 2? gin * 50 + lian * 5 : gin * 50;
		if( w % 100 == 0 )
			printf( "Case %d: %d\n", ++n, w / 100 );
		else if( w % 10 == 0 )
			printf( "Case %d: %d.%d\n", ++n, w / 100, w / 10 % 10 );
		else
			printf( "Case %d: %d.%d\n", ++n, w / 100, w % 100 );
	}
}
