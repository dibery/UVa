#include<cstdio>

int main()
{
	int t, a1, a2, seq, digit, pisano[] = { 0, 60, 300, 1500, 15000 }, pow10[] = { 1, 10, 100, 1000, 10000 };
	scanf( "%d", &t );

	while( t-- )
	{
		scanf( "%d %d %d %d", &a1, &a2, &seq, &digit );
		seq %= pisano[ digit ];
		a1 %= pow10[ digit ];
		a2 %= pow10[ digit ];
		int *cal = new int[ pisano[ digit ] ];
		cal[ 0 ] = a1, cal[ 1 ] = a2;
		for( int i = 2; i < pisano[ digit ] && i <= seq; ++i )
			cal[ i ] = ( cal[ i-1 ] + cal[ i-2 ] ) % pow10[ digit ];
		printf( "%d\n", cal[ seq ] );
	}

	return 0;
}
