#include<cstdio>
#include<climits>
#include<algorithm>
int t, ans[ 10001 ] = { 0 };

int main()
{
	for( int i = 1; i <= 10000; ++i )
	{
		int calc = INT_MAX;
		for( int j = 1; j*j <= i; ++j )
			calc = std::min( calc, 1 + ans[ i - j*j ] );
		ans[ i ] = calc;
	}
	for( scanf( "%d", &t ); scanf( "%d", &t ) != EOF; printf( "%d\n", ans[ t ] ) );

	return 0;
}
