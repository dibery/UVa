#include<cstdio>

int main()
{
	int t, size, in;

	scanf( "%d", &t );
	for( int n = 1; n <= t; ++n )
	{
		int count[ 101 ] = { 0 };
		bool ok = true;

		scanf( "%d", &size );
		for( int i = 0; i < size * size; ++i )
		{
			scanf( "%d", &in );
			ok &= ++count[ in ] <= size;
		}
		printf( "Case %d: %s\n", n, ok? "yes" : "no" );
	}
}
