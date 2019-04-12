#include<cstdio>
#include<cctype>

int main()
{
	int t, digit;
	char str[ 201 ], *pos, alpha;
	scanf( "%d\n", &t );

	for( int n = 1; n <= t; ++n )
	{
		gets( pos = str );
		printf( "Case %d: ", n );
		while( *pos )
		{
			sscanf( pos, "%c%d", &alpha, &digit );
			while( digit-- )
				putchar( alpha );
			for( ++pos; isdigit( *pos ); ++pos );
		}
		puts( "" );
	}
}
