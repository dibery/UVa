#include<cstdio>
#include<cstring>
int get( char* trace, char* end_point )
{
	int back = 0;
	for( ; trace >= end_point && *trace == 'O'; --trace )
		++back;
	return back;
}

int main()
{
	int t;
	char str[ 80 ];

	for( scanf( "%d", &t ); t--; )
	{
		int score = 0;
		scanf( "%s", str );

		for( int i = 0; str[ i ]; ++i )
			if( str[ i ] == 'O' )
				score += get( str+i, str );
		printf( "%d\n", score );
	}

	return 0;
}
