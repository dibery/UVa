#include<cstdio>
#include<set>

int main()
{
	int t, digit, ten[ 10 ] = { 1 };
	long long n;

	for( int i = 1; i < 10; ++i )
		ten[ i ] = ten[ i - 1 ] * 10;
	for( scanf( "%d", &t ); t--; )
	{
		std::set<int> show;

		scanf( "%d %lld", &digit, &n );
		while( show.find( n ) == show.end() )
		{
			show.insert( n );
			n *= n;
			while( n >= ten[ digit ] )
				n /= 10;
		}
		printf( "%d\n", *--show.end() );
	}
}
