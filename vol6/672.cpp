#include<cstdio>
#include<cstdlib>
#include<algorithm>
struct man
{
	int prosperity, stoutness, arrive;
	bool operator() ( const man& a, const man& b ) { return a.arrive != b.arrive? a.arrive < b.arrive : a.stoutness < b.stoutness; }
} ganster[ 101 ], obj;

int main()
{
	int t, people, state, time;

	for( scanf( "%d", &t ); t--; )
	{
		int ans[ 101 ] = { 0 }, lastTime[ 101 ] = { 0 }, out = 0;
		scanf( "%d %d %d", &people, &state, &time );
		ganster[ 0 ].arrive = 0;
		for( int i = 1; i <= people; ++i )
			scanf( "%d", &ganster[ i ].arrive );
		for( int i = 1; i <= people; ++i )
			scanf( "%d", &ganster[ i ].prosperity );
		for( int i = 1; i <= people; ++i )
			scanf( "%d", &ganster[ i ].stoutness );
		std::sort( ganster+1, ganster+people+1, obj );
		for( int i = 1; i <= people; ++i )
			for( int j = 0; j < i; ++j )
				if( lastTime[ j ] + abs( ganster[ i ].stoutness - ganster[ j ].stoutness ) <= ganster[ i ].arrive && ( lastTime[ j ] || !j ) && ans[ i ] <= ans[ j ] + ganster[ i ].prosperity )
					ans[ i ] = ans[ j ] + ganster[ i ].prosperity, lastTime[ i ] = ganster[ i ].arrive;
		for( int i = 1; i <= people; ++i )
			out = std::max( out, ans[ i ] );
		printf( "%d\n%s", out, t? "\n" : "" );
	}

	return 0;
}