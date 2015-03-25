#include<bits/stdc++.h>
using namespace std;

struct nation
{
	string name;
	int gold, silver, bronze;
	nation( string n = string( "Canada" ), int g = 0, int s = 0, int b = 0 )
	{
		name = n;
		gold = g;
		silver = s;
		bronze = b;
	}
	double calc( int total, double wg, double ws, double wb ) { return gold*pow( total, wg ) + silver*pow( total, ws ) + bronze*pow( total, wb ); }
} canada;

int main()
{
	string n;
	int size, g, s, b;

	while( cin >> size && size )
	{
		vector<nation> all;
		int medal = 0;
		bool ok = false;

		for( int i = 0; i < size; ++i )
		{
			cin >> n >> g >> s >> b;
			medal += s+g+b;
			if( n == "Canada" )
				canada = nation( n, g, s, b );
			else
				all.push_back( nation( n, g, s, b ) );
		}
		for( int i = -30; i <= 30 && !ok; ++i )
			for( int j = -30; j <= 30 && !ok; ++j )
				for( int k = -30, l; k <= 30 && !ok; ++k )
				{
					for( l = 0; l < size; ++l )
						if( all[ l ].calc( medal, i, j, k ) >= canada.calc( medal, i, j, k ) )
							break;
					if( l == size )
						ok = true;
				}
		puts( ok? "Canada wins!" : "Canada cannot win." );
	}
}
