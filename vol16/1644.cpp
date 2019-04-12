#include<cstdio>
#include<algorithm>
using namespace std;
int prime[ 100000 ] = { 2, 3, 5, 7 }, qnt = 4;
bool isprime( int n )
{
	for( int i = 1; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}
int gap( int n )
{
	int* low = lower_bound( prime, prime+100000, n );
	return *low == n? 0 : *low - *(low-1);
}

int main()
{
	int n;
	for( int i = 11; qnt <= 100000; i += 2 )
		if( isprime( i ) )
			prime[ qnt++ ] = i;
	while( scanf( "%d", &n ) && n )
		printf( "%d\n", gap( n ) );

	return 0;
}
