#include<cstdio>

int main()
{
	for( int n, note[ 10000 ]; scanf( "%d", &n ) == 1; )
	{
		int sum = 0;
		for( int i = 0; i < n; ++i )
			scanf( "%d", note+i ), sum += note[ i ];
		int ave = sum / n, diff = 0;
		for( int i = 0; i < n; ++i )
			if( note[ i ] < ave )
				diff += ave - note[ i ];
		printf( "%d\n", sum % n? -1 : diff+1 );
	}
}
