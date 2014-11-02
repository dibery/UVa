#include<cstdio>
#include<algorithm>
using namespace std;

int prime[ 333 ] = { 2 }, factor[ 5000001 ], deprime[ 900000 ], size = 1, dsize, L, H;

bool isp( int n )
{
	for( int i = 0; i < size && prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < 2236; i += 2 )
		if( isp( i ) )
			prime[ size++ ] = i;
	for( int i = 2; i <= 5000000; ++i )
	{
		for( int p = 0; p < size && !factor[ i ] && prime[ p ] * prime[ p ] <= i; ++p )
			if( i % prime[ p ] == 0 )
			{
				int tmp = i;
				while( tmp % prime[ p ] == 0 )
					tmp /= prime[ p ];
				factor[ i ] = factor[ tmp ] + prime[ p ];
				if( isp( factor[ i ] ) )
					deprime[ dsize++ ] = i;
			}
		if( !factor[ i ] )
			factor[ i ] = i, deprime[ dsize++ ] = i;
	}
	while( scanf( "%d", &L ) && L )
		scanf( "%d", &H ), printf( "%d\n", upper_bound( deprime, deprime+dsize, H ) - lower_bound( deprime, deprime+dsize, L ) );
}
