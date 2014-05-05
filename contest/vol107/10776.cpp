#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int stack[ 32 ];
char last[ 32 ] = { 0 };
void comb( char* str, int take, int level, int start = 0 )
{
	stack[ level ] = start;
	for( int i = start + ( take == level? 0 : 1 ); str[ i ]; ++i )
		if( take != level )
			if( i == start + 1 || str[ i ] != str[ i-1 ] )
				comb( str, take, level+1, i );
			else;
		else
		{
			char out[ 32 ] = { 0 };
			for( int i = 1; i <= take; ++i )
				out[ i-1 ] = str[ stack[ i ] ];
			if( strcmp( out, last ) > 0 )
				puts( out ), strcpy( last, out );
			break;
		}
	stack[ level ] = 0;
}

int main()
{
	char str[ 32 ] = { 0 };
	int take;

	while( scanf( "%s %d", str, &take ) == 2 )
	{
		sort( str, str + strlen( str ) );
		for( int i = 0; str[ i ]; ++i )
			if( !i || str[ i ] != str[ i-1 ] )
				comb( str, take, 1, i );
		memset( last, 0, sizeof( last ) );
	}
	return 0;
}
