#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
	int size, query, h[ 50000 ], n;

	scanf( "%d", &size );
	for( int i = 0; i < size; ++i )
		scanf( "%d", h+i );
	for( scanf( "%d", &query ); query; --query )
	{
		scanf( "%d", &n );
		int *low = lower_bound( h, h+size, n ) - 1, *high = upper_bound( h, h+size, n );
		printf( n <= *h? "X " : "%d ", *low );
		printf( n >= h[ size-1 ]? "X\n" : "%d\n", *high );
	}
}
