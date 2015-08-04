#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	char str[ 200 ];

	for( scanf( "%d\n", &t ); t; --t )
	{
		int len = strlen( gets( str ) );
		if( count( str, str+len, 'M' ) == count( str, str+len, 'F' ) && count( str, str+len, ' ' ) )
			puts( "LOOP" );
		else
			puts( "NO LOOP" );
	}
}
