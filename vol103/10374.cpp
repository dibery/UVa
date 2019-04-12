#include<cstdio>
#include<string>
#include<map>
using namespace std;

int main()
{
	int t, cand, vote;
	char name[ 81 ], party[ 81 ];
	string win;

	for( scanf( "%d", &t ); t--; )
	{
		map<string,int> stat;
		map<string,string> belong;
		int M = 0;
		bool dup = false;

		for( scanf( "%d\n", &cand ); cand--; )
		{
			gets( name );
			gets( party );
			belong[ string( name ) ] = string( party );
		}
		for( scanf( "%d\n", &vote ); vote--; )
		{
			gets( name );
			if( belong.find( string( name ) ) != belong.end() )
				++stat[ string( name ) ];
		}
		for( auto& i: stat )
			if( i.second > M )
				M = i.second, dup = false, win = i.first;
			else if( i.second == M )
				dup = true;
		if( dup || !M )
			puts( "tie" );
		else
			puts( belong[ win ].c_str() );
		if( t )
			puts( "" );
	}
}
