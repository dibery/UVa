#include<cstdio>
#include<algorithm>
using namespace std;
char str[ 1000001 ], *ptr;
char* space( char *pos, int& longest )
{
	int len = 0;

	while( *pos == ' ' )
		++len, ++pos;
	longest = max( longest, len );

	return pos;
}
int time( int n )
{
	int t = 0;

	while( n != 1 )
		n -= n >> 1, ++t;

	return t;
}

int main()
{
	while( gets( str ) )
	{
		int longest = 0;

		for( ptr = str; *ptr; ++ptr )
			if( *ptr == ' ' )
				ptr = space( ptr, longest );
		printf( "%d\n", longest? time( longest ) : 0 );
	}

	return 0;
}
