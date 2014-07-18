#include<cstdio>
#include<cstdlib>
#include<cmath>
int gcd( int a, int b ) { return a % b == 0? b : gcd( b, a % b ); }

int main()
{
	int size, val[ 100 ], factor, integer, up, down, t = 0, lu, ld, li;

	while( scanf( "%d", &size ) && size )
	{
		int sum = 0, pos;
		
		for( int i = 0; i < size; ++i )
			scanf( "%d", val+i ), sum += val[ i ];

		factor = size && ( pos = sum )? gcd( size, pos = abs( sum ) ) : 1;
		integer = pos / size;
		up = pos % size / factor;
		down = size / factor;
		lu = up? log10( up ) + 1e-12 + 1 : 0;
		ld = log10( down ) + 1e-12 + 1;
		li = integer? log10( integer ) + 1e-12 + 1 : 0;

		printf( "Case %d:\n", ++t );
		if( up == 0 )
			if( sum < 0 )
				printf( "- %d\n", integer );
			else
				printf( "%d\n", integer );
		else//
			if( sum < 0 )
			{
				printf( "  " );
				for( int i = ld + li - lu; i; --i )
					putchar( ' ' );
				printf( "%d\n", up );
				printf( "- " );
				if( integer )
					printf( "%d", integer );
				for( int i = 0; i < ld; ++i )
					putchar( '-' );
				printf( "\n  " );
				for( int i = li; i; --i )
					putchar( ' ' );
				printf( "%d\n", down );
			}
			else
			{
				for( int i = ld + li - lu; i; --i )
					putchar( ' ' );
				printf( "%d\n", up );
				if( integer )
					printf( "%d", integer );
				for( int i = 0; i < ld; ++i )
					putchar( '-' );
				puts( "" );
				for( int i = li; i; --i )
					putchar( ' ' );
				printf( "%d\n", down );
			}
	}
}
