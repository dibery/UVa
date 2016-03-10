#include<cstdio>

const int N = 2001;
char str[ N ][ N ];

int diff( char* a, char* b )
{
	int ret = 0;
	
	for( int i = 0; a[ i ]; ++i )
		ret += a[ i ] != b[ i ];

	return ret;
}

int main()
{
	for( int word, len; scanf( "%d %d\n", &word, &len ) == 2; )
	{
		bool used[ N ] = { true };
		int last = 0, out = 1;

		for( int i = 0; i < word; ++i )
			gets( str[ i ] );

		puts( *str );
		while( out < word )
			for( int i = 1; i < word; ++i )
				if( !used[ i ] && diff( str[ last ], str[ i ] ) == 1 )
					puts( str[ last = i ] ), ++out, ++used[ i ];
	}
}
