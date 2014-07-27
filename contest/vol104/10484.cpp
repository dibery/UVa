#include<cstdio>

int main()
{
	int fact, div;

	while( scanf( "%d %d", &fact, &div ) && fact + div )
	{
		int has[ 100 ] = { 0 };
		bool ok = true;
		if( div < 0 )
			div = -div;

		for( int i = 2; i <= fact; ++i )
		{
			int tmp = i;
			for( int n = 2; n <= tmp; ++n )
				while( tmp % n == 0 )
					++has[ n ], tmp /= n;
		}
		for( int i = 2; ok && i < 100 && i <= div; ++i )
			for( ; div % i == 0 && ok; ok = has[ i ] >= 0 )
				--has[ i ], div /= i;
		ok &= div == 1;
		long long int ans = ok;
		for( int i = 2; i < 100; ++i )
			if( has[ i ] )
				ans *= has[ i ] + 1;
		printf( "%lld\n", ans );
	}
}
