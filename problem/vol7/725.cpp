#include<cstdio>
bool rep( int n, int x = -1 )
{
	int has[ 10 ] = { 0 };
	for( int i = 0; i < 5; ++i )
		++has[ n % 10 ], n /= 10;
	for( int i = 0; i < 5 && x >= 0; ++i )
		++has[ x % 10 ], x /= 10;
	for( int i = 0; i < 10; ++i )
		if( has[ i ] > 1 )
			return true;
	return false;
}

int main()
{
	int n;
	bool first = true;

	while( scanf( "%d", &n ) && n )
	{
		int out = 0;
		printf( first? "" : "\n" );
		first = false;
		for( int i = 1234; i * n <= 98765; ++i )
			if( !rep( i ) )
				if( !rep( i * n, i ) )
					printf( "%05d / %05d = %d\n", i * n, i, n ), ++out;
		if( !out )
			printf( "There are no solutions for %d.\n", n );
	}

	return 0;
}
