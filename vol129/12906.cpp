#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;

int main()
{
	int t, size, v, f;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		map<ull,ull> item;
		ull score = 0, perm = 1, now = 0;

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
		{
			scanf( "%d %d", &v, &f );
			item[ v ] = f;
		}

		for( map<ull,ull>::iterator i = item.begin(); i != item.end(); ++i )
		{
			score += ( now += i->second ) * i->second;
			if( next( i ) != item.end() )
				perm = ( perm * ++i->second ) % 1000000007;
		}
		printf( "Case %d: %llu %llu\n", n, score, perm );
	}
}
