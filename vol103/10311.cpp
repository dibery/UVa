#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 100000000;
bool notprime[ N+1 ];
int all[ 5770000 ], size = 0, in;

int main()
{
	notprime[ 0 ] = notprime[ 1 ] = true;
	for( int i = 3; i < 10000; i += 2 )
		if( !notprime[ i ] )
			for( int j = i*i; j <= N; j += i << 1 )
				notprime[ j ] = true;
	all[ size++ ] = 2;
	for( int i = 3; i <= N; i += 2 )
		if( !notprime[ i ] )
			all[ size++ ] = i;

	while( scanf( "%d", &in ) == 1 )
	{
		int *pos = lower_bound( all, all+size, in/2 ) - 1;
		if( in % 2 == 1 )
			if( in > 1 && !notprime[ in-2 ] )
				printf( "%d is the sum of %d and %d.\n", in, 2, in-2 );
			else
				printf( "%d is not the sum of two primes!\n", in );
		else
		{
			for( ; pos >= all && ( notprime[ *pos ] || notprime[ in - *pos ] ); --pos );
			if( pos <= all )
				printf( "%d is not the sum of two primes!\n", in );
			else
				printf( "%d is the sum of  %d and %d.\n", in, *pos, in - *pos );
		}
	}
}
