#include<cstdio>
#include<cstring>
#include<algorithm>

void perm( char* pushed, char* topush, int len )
{
	if( strlen( pushed ) == len )
	{
		puts( pushed );
		return;
	}
	char p[ 11 ] = { *topush };
	strcpy( p+1, pushed );
	for( int i = 1; i <= strlen( p ); ++i )
	{
		perm( p, topush+1, len );
		std::swap( p[ i ], p[ i-1 ] );
	}
}

int main()
{
	char str[ 10 ];

	gets( str );
	perm( "", str, strlen( str ) );
	while( gets( str ) )
		puts( "" ), perm( "", str, strlen( str ) );
}
