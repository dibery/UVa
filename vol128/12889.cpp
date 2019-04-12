#include<cstdio>

int main()
{
	int t, size, first;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &size, &first );
		bool win = size > 1, diff = false;

		for( int i = 1, n; i < size; ++i )
			scanf( "%d", &n ), diff |= n != first;
		puts( win && diff && first? "Happy Birthday Tutu!" : "Better luck next time!" );
	}
}
