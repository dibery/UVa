#include<cstdio>
#include<cmath>

long long int prime[ 100000 ] = { 2 }, size = 1;

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

void dfs( long long int now, int& count, long long int n, int pos = 1 )
{
	long long int init = now;
	for( ; now <= n && now > 0; now *= prime[ pos ] * prime[ pos ] )
	{
		if( now != init )
			++count;
		if( pos < size-1 && prime[ pos+1 ] * prime[ pos+1 ] <= n / now )
			dfs( now, count, n, pos+1 );
	}
}

int main()
{
	long long int n;

	for( int i = 3; i < 1000000; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;

	while( scanf( "%lld", &n ) && n )
	{
		int odd = 0;
		for( long long int t = 1; t <= n; t <<= 1 )
			dfs( t, odd, n ), ++odd;
		printf( "%lld\n", n-odd );
	}
}
