#include<cstdio>

int main()
{
	int t, n;
	for( scanf( "%d", &t ); t-- && scanf( "%d", &n ); puts( "" ) )
	{
		bool shown[ 100000 ] = { false };
		printf( "0." );
		for( int r = 1; !shown[ r ]; r = r * 10 % n )
			shown[ r ] = true, printf( "%d", r * 10 / n );
	}
}
