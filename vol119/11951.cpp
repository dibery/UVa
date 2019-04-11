#include<cstdio>
#include<algorithm>
#include<utility>
using namespace std;

pair<int,int> calc( int* cost, int size, int budget )
{
	int area = 0, total = 0, begin = 0, end = 0, sum[ 101 ] = { 0 };

	for( int i = 1; i <= size; ++i )
		sum[ i ] = sum[ i-1 ] + cost[ i-1 ];
	
	for( end = 1; end <= size; ++end )
		if( sum[ end ] - sum[ begin ] <= budget )
		{
			if( end - begin > area || end - begin == area && sum[ end ] - sum[ begin ] < total )
			{
				area = end - begin;
				total = sum[ end ] - sum[ begin ];
			}
		}
		else
		{
			while( sum[ end ] - sum[ begin ] > budget && begin <= end )
				++begin;
			--end;
		}
	return pair<int,int> ( area, total );
}

int main()
{
	int t, land[ 100 ][ 100 ], h, w, money;
	scanf( "%d", &t );

	for( int n = 1; n <= t; ++n )
	{
		int area = 0, cost = 0;
		scanf( "%d %d %d", &h, &w, &money );
		for( int i = 0; i < h; ++i )
			for( int j = 0; j < w; ++j )
				scanf( "%d", &land[ i ][ j ] );
		for( int i = 0; i < h; ++i )
		{
			int tmp[ 100 ] = { 0 };
			for( int j = i; j < h; ++j )
			{
				for( int k = 0; k < w; ++k )
					tmp[ k ] += land[ j ][ k ];
				pair<int,int> result = calc( tmp, w, money );
				result.first *= j-i+1;
				if( result.first > area || result.first == area && result.second < cost )
					area = result.first, cost = result.second;
			}
		}
		printf( "Case #%d: %d %d\n", n, area, cost );
	}
}
