#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int ks[ 10001 ][ 200 ];
bool use[ 10001 ][ 200 ];

int main()
{
	int t, ferry;

	for( scanf( "%d", &t ); t-- && scanf( "%d", &ferry ); printf( t? "\n" : "" ) )
	{
		ferry *= 100;
		vector<int> car;
		bool goto_right[ 200 ] = { false };
		int sum[ 200 ] = { 0 }, stop;

		fill( ks[ 0 ], ks[ 10001 ], 0 );
		fill( use[ 0 ], use[ 10001 ], false );

		for( int n; scanf( "%d", &n ) && n; )
			car.push_back( n );
		if( car.size() > 200 )
			car.erase( car.begin() + 200, car.end() );
		else if( car.empty() )
		{
			puts( "0" );
			continue;
		}
		
		sum[ 0 ] = car[ 0 ];
		for( int i = 1; i < car.size(); ++i )
			sum[ i ] = sum[ i - 1 ] + car[ i ];
		
		for( int w = car[ 0 ]; w <= ferry; ++w )
			ks[ w ][ 0 ] = car[ 0 ], use[ w ][ 0 ] = true;
		for( int w = 0; w <= ferry; ++w )
			for( int i = 1; i < car.size(); ++i )
				if( w >= car[ i ] )
					if( ks[ w ][ i - 1 ] >= car[ i ] + ks[ w - car[ i ] ][ i - 1 ] )
						ks[ w ][ i ] = ks[ w ][ i - 1 ];
					else
						ks[ w ][ i ] = car[ i ] + ks[ w - car[ i ] ][ i - 1 ], use[ w ][ i ] = true;
				else
					ks[ w ][ i ] = ks[ w ][ i - 1 ];
		for( stop = 0; sum[ stop ] - ks[ ferry ][ stop ] <= ferry && stop < car.size(); ++stop )
			;
		for( int w = ferry, i = stop - 1; i >= 0 && w > 0; --i )
			if( use[ w ][ i ] )
				goto_right[ i ] = true, w -= car[ i ];

		printf( "%d\n", stop );
		for( int i = 0; i < stop; ++i )
			puts( goto_right[ i ]? "port" : "starboard" );
	}
}
