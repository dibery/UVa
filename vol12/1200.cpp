#include<cstdio>
#include<cmath>
#include<cstring>
#include<cctype>

int main()
{
	int t, tmp;
	char in[ 256 ], *pos;

	for( scanf( "%d\n", &t ); t; --t )
	{
		double X = 0, C = 0, sign = 1, ans;
		gets( pos = in );
		char *equal = strchr( in, '=' );

		for( ; *pos; ++pos )
			if( pos == equal )
				sign = -1;
			else if( *pos == '-' )
				sign = pos < equal? -1 : 1;
			else if( *pos == '+' )
				sign = pos < equal? 1 : -1;
			else if( *pos == 'x' )
				X += sign;
			else
			{
				char *x = strchr( pos, 'x' ), *plus = strchr( pos, '+' ), *minus = strchr( pos, '-' );
				sscanf( pos, "%d", &tmp );
				if( x == NULL || plus && x > plus || minus && x > minus || pos < equal && x > equal )
					C += sign * tmp;
				else
					X += sign * tmp;
				while( isdigit( *(pos+1) ) || *(pos+1) == 'x' )
					++pos;
			}
		if( X == 0 )
			if( C == 0 )
				puts( "IDENTITY" );
			else
				puts( "IMPOSSIBLE" );
		else
			printf( "%.0f\n", ( ans = floor( -C / X ) )? ans : 0 );
	}
}
