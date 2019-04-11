#include<cstdio>
#include<cmath>
#include<cstring>
int time( int& n, int div )
{
	int t = 0;
	while( n % div == 0 )
		n /= div, ++t;
	return t;
}
bool isprime( int n )
{
	for( int i = 2; i*i <= n; ++i )
		if( n % i == 0 )
			return false;
	return true;
}

int main()
{
	char in[ 1000 ] = { 0 };
	while( gets( in ) && strcmp( in, "0" ) )
	{
		int base[ 1000 ] = { 0 }, exp[ 1000 ] = { 0 }, cnt = 0, num = 1;

		for( int i = 0; in[ i ]; ++i )
			if( !i || in[ i-1 ] == ' ' )
				if( cnt % 2 )
					sscanf( in+i, "%d", &exp[ cnt++ / 2 ] );
				else
					sscanf( in+i, "%d", &base[ ++cnt / 2 ] );
		for( int i = 0; i < cnt / 2; ++i )
			num *= pow( base[ i ], exp[ i ] ) + 1e-12;
		--num;

		for( int i = num; num != 1; --i )
			if( num % i == 0 && isprime( i ) )
				printf( "%d %d", i, time( num, i ) ), putchar( num == 1? '\n' : ' ' );
	}
	return 0;
}
