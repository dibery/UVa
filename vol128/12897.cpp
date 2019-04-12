#include<cstdio>

int main()
{
	char str[ 1000001 ] = { 0 }, a, b;
	int t, rule;

	for( scanf( "%d\n", &t ); t--; )
	{
		char map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		gets( str );
		for( scanf( "%d\n", &rule ); rule--; )
		{
			scanf( "%c %c\n", &a, &b );
			for( char& c: map )
				if( c == b )
					c = a;
		}
		for( int i = 0; str[ i ]; ++i )
			if( str[ i ] != '_' )
				str[ i ] = map[ str[ i ] - 'A' ];
		puts( str );
	}
}
