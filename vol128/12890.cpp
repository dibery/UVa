#include<cstdio>
#include<unordered_set>
using namespace std;

int main()
{
	int t, size, n[ 100000 ] = { 0 };

	for( scanf( "%d", &t ); t--; )
	{
		unordered_set<int> exist;
		long long ans = 0;

		scanf( "%d", &size );
		for( int i = 0; i < size; ++i )
			scanf( "%d", n + i );

		for( int begin = 0, end = 0; begin != size || end != size; )
		{
			while( end < size && exist.find( n[ end ] ) == exist.end() )
				exist.insert( n[ end++ ] );
			while( begin < end && ( end == size || exist.find( n[ end ] ) != exist.end() ) )
				ans += end - begin, exist.erase( n[ begin++ ] );
		}
		printf( "%lld\n", ans );
	}
}
