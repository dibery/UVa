#include<cstdio>

int main()
{
	int T = 0, n;
	char s[ 101 ];

	while( scanf( "%d\n", &n ) && n )
	{
		printf( "Case %d:\n", ++T );
		puts( "#include<string.h>\n#include<stdio.h>\nint main()\n{" );
		while( n-- && gets( s ) )
		{
			printf( "printf(\"" );
			for( int i = 0; s[ i ]; ++i )
			{
				if( s[ i ] == '"' || s[ i ] == '\\' )
					putchar( '\\' );
				putchar( s[ i ] );
			}
			puts( "\\n\");" );
		}
		puts( "printf(\"\\n\");\nreturn 0;\n}" );
	}
}
