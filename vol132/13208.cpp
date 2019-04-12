#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t, depth, wall, dx[ 10001 ] = { 0 }, h[ 10001 ];

	for( scanf( "%lld", &t ); t-- && scanf( "%lld %lld", &depth, &wall ); )
	{
		for( long long i = 1; i <= wall; ++i )
			scanf( "%lld", dx + i );
		for( long long i = 0; i <= wall; ++i )
			scanf( "%lld", h + i );

		vector<pair<long long,long long>> data;
		data.emplace_back( 0, h[ 0 ] );
		data.emplace_back( dx[ 1 ], h[ 1 ] );
		for( long long i = 2, x = dx[ 1 ]; i <= wall && ( x += dx[ i ] ); ++i )
		{
			while( data.size() > 1 && data.back().second <= h[ i ] && data.back().second <= data[ data.size() - 2 ].second )
				data.pop_back();
			data.emplace_back( x, h[ i ] );
		}

		long long vol = 0;
		for( long long i = 1; i < data.size(); ++i )
			vol += ( data[ i ].first - data[ i - 1 ].first ) * min( data[ i ].second, data[ i - 1 ].second );
		printf( "%lld\n", vol * depth );
	}
}
