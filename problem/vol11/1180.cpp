#include<cstdio>

int main()
{
	int t, n;
	bool yes[ 18 ] = { false, false, true, true, false, true, false, true, false, false, false, false, false, true, false, false, false, true };
	scanf( "%d", &t );

	while( t-- )
		scanf( "%d%*c", &n ), puts( n >= 2 && n <= 17 && yes[ n ]? "Yes" : "No" );

	return 0;
}

/*int main()
{
	freopen( "out.txt", "w", stdout );
	long long int pow2[ 34 ] = { 1 };
	for( int i = 1; i < 34; ++i )
		pow2[ i ] = pow2[ i-1 ] << 1;
	for( int i = 1; i <= 17; ++i )
	{
		long long int now = pow2[ i-1 ] * ( pow2[ i ] - 1 ), sum = 0;
		for( long long int k = 1; k*k <= now; ++k )
			if( now % k == 0 )
				sum += ( k*k == now? k : k + now / k );
		if( sum == now * 2 )
			printf( "%d\n", i );
	}

	return 0;
}*/
