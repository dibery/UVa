#include<cstdio>
#include<cstring>

int check( char* str, int cost[] )
{
	int time = 0;
	for( ++str; *str != '/'; ++str )
		time += cost[ *str - 'A' ];
	return time == 64;
}

int main()
{
	char in[ 201 ], *begin, *end;
	int cost[ 26 ];
	cost[22] = 64, cost[7] = 32, cost[16] = 16, cost[4] = 8, cost[18] = 4, cost[19] = 2, cost[23] = 1;

	while( gets( begin = in ) && *in != '*' )
	{
		int ok = 0;
		for( end = strchr( begin+1, '/' ); end; end = strchr( ( begin = end ) + 1, '/' ) )
			ok += check( begin, cost );
		printf( "%d\n", ok );
	}
}
