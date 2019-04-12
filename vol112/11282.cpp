#include<cstdio>

int main()
{
	long long fact[ 21 ] = { 1 };

	for( int i = 1; i <= 20; ++i )
		fact[ i ] = fact[ i - 1 ] * i;

	for( int man, come; scanf( "%d %d", &man, &come ) == 2; )
	{
		long long ans = 0;

		for( int c = 0; c <= come; ++c )
		{
			long long scramble = 0, miss = man - c;
			for( int i = 0; i <= miss; ++i )
				scramble += ( i % 2? -1 : 1 ) * fact[ miss ] / fact[ i ] / fact[ miss - i ] * fact[ miss - i ];
			ans += fact[ man ] / fact[ c ] / fact[ man - c ] * scramble;
		}
		printf( "%lld\n", ans );
	}
}
