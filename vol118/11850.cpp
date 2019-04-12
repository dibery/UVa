#include<cstdio>
#include<algorithm>
#include<functional>

int main()
{
	int s, station[ 1500 ];

	while( scanf( "%d", &s ) && s )
	{
		for( int i = 0; i < s; ++i )
			scanf( "%d", station+i );
		std::sort( station, station+s, std::greater<int>() );
		bool ok = *station >= 1322 && station[ s-1 ] <= 200;
		for( int i = 0; i < s-1 && ok; ++i )
			if( station[ i ] - station[ i+1 ] > 200 )
				ok = false;
		puts( ok? "POSSIBLE" : "IMPOSSIBLE" );
	}
}
