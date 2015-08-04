#include<bits/stdc++.h>

int main()
{
	int pnt, cnt;
	char act[ 100001 ], *p, Do;

	while( scanf( "%d%*c", &pnt ) && pnt )
	{
		int r = 0;
		bool flip = false;

		for( gets( p = act ); p && *p; p = strchr( p, ' ' )? strchr( p, ' ' ) + 1 : NULL )
		{
			sscanf( p, "%c%d", &Do, &cnt );
			if( Do == 'r' )
				if( !flip )
					r = ( r + cnt ) % pnt;
				else
					r = ( r - cnt + pnt ) % pnt;
			else
				flip ^= cnt % 2 != 0;
		}

		if( r > 0 )
			if( flip )
				if( pnt - r > r )
					printf( "r%d m1", r );
				else
					printf( "m1 r%d", pnt - r );
			else if( pnt - r + 2 > r )
				printf( "r%d", r );
			else
				printf( "m1 r%d m1", pnt - r );
		else if( r < 0 )
			if( flip )
				if( pnt + r > -r )
					printf( "m1 r%d", -r );
				else
					printf( "r%d m1", pnt + r );
			else
				if( pnt + r + 2 > r )
					printf( "r%d", -r );
				else
					printf( "m1 r%d m1", pnt + r );
		else if( flip )
			printf( "m1" );
		puts( "" );
	}
}
