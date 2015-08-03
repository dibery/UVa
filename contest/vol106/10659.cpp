#include<bits/stdc++.h>
const int MAX = 10000000;
using namespace std;

int calc( const string& s, size_t width, int size )
{
	int line = 1;
	vector<int> len;
	stringstream ss( s );

	for( string t; ss >> t; len.push_back( t.size() ) )
		if( t.size() * size > width )
			return MAX;
	for( int now = 0; !len.empty(); )
		if( now + ( ( now != 0 ) + len[ 0 ] ) * size > width )
			now = 0, ++line;
		else
			now += ( ( now != 0 ) + len[ 0 ] ) * size, len.erase( len.begin() );
	return line * size;
}

int main()
{
	int slide, para, size, h, w;

	for( scanf( "%d", &slide ); slide--; )
	{
		scanf( "%d\n", &para );
		string text[ para ];

		for( int i = 0; i < para; ++i )
			getline( cin, text[ i ] );
		scanf( "%d %d", &w, &h );

		for( size = 28; size >= 8; --size )
		{
			int need = 0;
			for( int i = 0; i < para && need <= h; ++i )
				need += calc( text[ i ], w, size );
			if( need <= h )
				break;
		}

		if( size >= 8 )
			printf( "%d\n", size );
		else
			puts( "No solution" );
	}
}
