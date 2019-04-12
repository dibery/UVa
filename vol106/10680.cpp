#include<cstdio>
int prime[ 80000 ] = { 2 }, size = 1, ans[ 1000001 ] = { 0, 1 }, stat[ 1000001 ], in;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int time( int& n, int div )
{
	int ans = 0;
	while( n % div == 0 )
		n /= div, ++ans;
	return ans;
}

void elim_zero( int& n )
{
	while( n % 10 == 0 )
		n /= 10;
	n %= 10;
}

int main()
{
	for( int i = 3; i < 1000001; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	for( int i = 2; i <= 1000000; ++i )
	{
		int tmp = i;
		ans[ i ] = ans[ i-1 ];
		for( int j = 0; j < size && prime[ j ] * prime[ j ] <= tmp; ++j )
			if( i % prime[ j ] == 0 )
			{
				int n = time( tmp, prime[ j ] );
				if( n > stat[ prime[ j ] ] )
				{
					for( int diff = n - stat[ prime[ j ] ]; diff; --diff )
						elim_zero( ans[ i ] *= prime[ j ] == 5? 8 : prime[ j ] );
					stat[ prime[ j ] ] = n;
				}
			}
		if( tmp > 1 && !stat[ tmp ] )
			elim_zero( ans[ i ] *= tmp == 5? 8 : tmp ), stat[ tmp ] = 1;
	}

	while( scanf( "%d", &in ) && in )
		printf( "%d\n", ans[ in ] );
}
