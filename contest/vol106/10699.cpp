#include<cstdio>

int main()
{
	for( int n; scanf( "%d", &n ) && n; )
	{
		int prime = 0, N = n;

		for( int i = 2; i < 1000; ++i )
			if( n % i == 0 )
			{
				++prime;
				while( n % i == 0 )
					n /= i;
			}
		printf( "%d : %d\n", N, prime + ( n != 1 ) );
	}
}
