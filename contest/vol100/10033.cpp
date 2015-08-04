#include<cstdio>
#include<cstdlib>

int main()
{
	int t;
	char s[ 4 ];

	for( scanf( "%d\n", &t ); t--; )
	{
		int reg[ 10 ] = { 0 }, ram[ 1000 ] = { 0 }, size = 0, ans = 0, pos = 0;

		while( gets( s ) && *s )
			ram[ size++ ] = atoi( s );

		while( ram[ pos ] != 100 )
		{
			int cmd = ram[ pos ] / 100, first = ram[ pos ] / 10 % 10, second = ram[ pos ] % 10;
			++ans;
			if( cmd == 2 )
				reg[ first ] = second;
			else if( cmd == 3 )
				reg[ first ] = reg[ first ] + second;
			else if( cmd == 4 )
				reg[ first ] = reg[ first ] * second;
			else if( cmd == 5 )
				reg[ first ] = reg[ second ];
			else if( cmd == 6 )
				reg[ first ] = reg[ first ] + reg[ second ];
			else if( cmd == 7 )
				reg[ first ] = reg[ first ] * reg[ second ];
			else if( cmd == 8 )
				reg[ first ] = ram[ reg[ second ] ];
			else if( cmd == 9 )
				ram[ reg[ second ] ] = reg[ first ];
			else if( reg[ second ] )
				pos = reg[ first ];
			if( cmd || !reg[ second ] )
				++pos;
			reg[ first ] %= 1000;
		}
		printf( "%d\n%s", ans+1, t? "\n" : "" );
	}
}
