#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	char in[ 500 ], *pos;
	int ascii;

	while( gets( pos = in ) )
		if( isdigit( *in ) )
		{
			reverse( in, in+strlen( in ) );
			while( *pos )
			{
				if( *pos == '1' )
					sscanf( pos, "%3d", &ascii ), pos += 3;
				else
					sscanf( pos, "%2d", &ascii ), pos += 2;
				putchar( ascii );
			}
			puts( "" );
		}
		else
		{
			char encode[ 500 ] = { 0 };
			for( int i = 0; in[ i ]; ++i )
				sprintf( encode+strlen( encode ), "%d", in[ i ] );
			reverse( encode, encode+strlen( encode ) );
			puts( encode );
		}
}
