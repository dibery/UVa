#include<cstdio>
#include<cstdlib>

int main()
{
	for( char a[ 6 ], b[ 6 ]; scanf( "%s %s %s %s %s %s %s %s %s %s ", a, a+1, a+2, a+3, a+4, b, b+1, b+2, b+3, b+4 ) == 10; puts( ( strtol( a, NULL, 2 ) ^ strtol( b, NULL, 2 ) ) == 31? "Y" : "N" ) );
}
