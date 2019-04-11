#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
	int t = 0, len;
	long double s2 = sqrt( (long double)2 );
	char s[ 201 ] = { 0 }, *p, sep, dir[ 3 ] = { 0 };

	while( strcmp( p = gets( s ), "END" ) )
	{
		long double x = 1e-9, y = 1e-9;

		for( ; sscanf( p, "%d%[NEWS]%c", &len, dir, &sep ) == 3; p = strchr( p, sep ) + 1 )
			if( strlen( dir ) == 1 )
				if( *dir == 'N' )
					y += len;
				else if( *dir == 'E' )
					x += len;
				else if( *dir == 'S' )
					y -= len;
				else
					x -= len;
			else
				for( int i = 0; dir[ i ]; ++i )
					if( dir[ i ] == 'N' )
						y += len / s2;
					else if( dir[ i ] == 'E' )
						x += len / s2;
					else if( dir[ i ] == 'S' )
						y -= len / s2;
					else
						x -= len / s2;

		printf( "Map #%d\nThe treasure is located at (%.3Lf,%.3Lf).\nThe distance to the treasure is %.3f.\n\n", ++t, x, y, hypot( x, y ) );
	}
}
