#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int main()
{
	int t, goal;
	double begin, end;
	char B[ 50 ], E[ 50 ];

	for( scanf( "%d", &t ); t--; )
	{
		pair<char*,char*> seg[ 100000 ];
		int size = 0, index = 0, use = 0, p[ 100000 ], ps = 0;
		bool ok = true;

		scanf( "%d\n", &goal );
		while( scanf( "%s %s", B, E ) && ( strcmp( B, "0" ) || strcmp( E, "0" ) ) )
			if( atof( E ) > 0 )
				seg[ size++ ] = make_pair( strdup( B ), strdup( E ) );
		sort( seg, seg+size, [] ( const pair<char*,char*>& a, const pair<char*,char*>& b ) { return atof( a.first ) < atof( b.first ); } );

		for( begin = 0, end = goal; begin < end; ++use )
		{
			if( atof( seg[ index ].first ) > begin || index >= size )
			{
				ok = false;
				break;
			}
			while( atof( seg[ index ].second ) <= begin && index < size )
				++index;
			if( atof( seg[ index ].first ) > begin || index >= size )
			{
				ok = false;
				break;
			}
			double M = index < size? atof( seg[ index ].second ) : -1, P = index;
			for( ; index < size && atof( seg[ index ].first ) <= begin; ++index )
				if( M < atof( seg[ index ].second ) )
					M = atof( seg[ index ].second ), P = index;
			begin = M;
			p[ ps++ ] = P;
		}
		if( ok )
		{
			printf( "%d\n", use );
			for( int i = 0; i < ps; ++i )
				printf( "%s %s\n", seg[ p[ i ] ].first, seg[ p[ i ] ].second );
		}
		else
			puts( "0" );
		if( t )
			puts( "" );
	}
}
