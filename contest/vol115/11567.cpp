#include<cstdio>

int main()
{
	unsigned int n;

	while( scanf( "%u", &n ) == 1 )
	{
		int step = n? 0 : -1;

		while( n > 1 )
		{
			while( n % 2 == 0 )
				n >>= 1, ++step;
			if( n == 3 )
				step += 2, n = 1;
			if( n == 1 )
				break;
			if( ( n-1 ) / 2 % 2 == 0 )
				--n, ++step;
			else
				++n, ++step;
		}
		printf( "%d\n", step+1 );
	}
}
