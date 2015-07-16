#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 31269
using namespace std;

int main()
{
	unsigned len[ N ] = { 0 }, sum[ N ] = { 0 }, t, n;

	for( int i = 1; i < N; ++i )
		sum[ i ] = ( len[ i ] = log10( i ) + 1 + len[ i-1 ] ) + sum[ i-1 ];
	for( scanf( "%u", &t ); t; --t )
	{
		scanf( "%u", &n );
		unsigned *p = lower_bound( sum, sum + N, n ), index = p - sum;
		char s[ 150000 ] = { 0 }, *end = s;
		for( int i = 1; i <= index; ++i )
			sprintf( end, "%d", i ), end += strlen( end );
		printf( "%c\n", s[ n - *--p - 1 ] );
	}
}
