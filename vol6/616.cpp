#include<cstdio>

bool ok( int coconuts, int people )
{
	for( int i = 0; i < people; ++i )
		if( coconuts % people != 1 )
			return false;
		else
			coconuts -= coconuts / people + 1;
	if( coconuts % people )
		return false;
	return true;
}

int main()
{
	for( int n; scanf( "%d", &n ) && n >= 0; )
	{
		int ans = 0;
		for( int i = 1; i < 30; ++i )
			if( ok( n, i ) )
				ans = i;
		if( ans )
			printf( "%d coconuts, %d people and 1 monkey\n", n, ans );
		else
			printf( "%d coconuts, no solution\n", n );
	}
}
