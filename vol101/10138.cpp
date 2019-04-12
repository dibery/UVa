#include<bits/stdc++.h>
using namespace std;

struct trip
{
	int D, H, M, pos;
	char dir[ 6 ];
	static int rate[ 24 ];

	trip() {}
	trip( const trip& rhs )
	{
		D = rhs.D;
		H = rhs.H;
		M = rhs.M;
		pos = rhs.pos;
		strcpy( dir, rhs.dir );
	}
	bool operator< ( const trip& cmp )
	{
		if( D != cmp.D )
			return D < cmp.D;
		return H != cmp.H? H < cmp.H : M < cmp.M;
	}
};

int trip::rate[ 24 ];

int main()
{
	int t;
	char s[ 50 ] = { 0 }, name[ 21 ];
	trip tmp;

	scanf( "%d", &t );
	for( int n = 0; n < t; ++n )
	{
		map<string,vector<trip>> record;

		if( n )
			puts( "" );
		
		for( int i = 0; i < 24; ++i )
			scanf( "%d", trip::rate + i );
		for( gets( s ); gets( s ) && *s; )
		{
			sscanf( s, "%s %*d:%d:%d:%d %s %d", name, &tmp.D, &tmp.H, &tmp.M, tmp.dir, &tmp.pos );
			record[ string( name ) ].push_back( tmp );
		}

		for( auto& i: record )
		{
			int cost = 0;
			sort( i.second.begin(), i.second.end() );
			for( auto j = i.second.begin(); next( j ) != i.second.end(); ++j )
				if( !strcmp( j->dir, "enter" ) && !strcmp( next( j )->dir, "exit" ) )
					cost += abs( j->pos - next( j )->pos ) * tmp.rate[ j->H ] + 100;
			if( cost )
				printf( "%s $%d.%02d\n", i.first.c_str(), cost / 100 + 2, cost % 100 );
		}
	}
}
