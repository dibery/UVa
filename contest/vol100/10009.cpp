#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
class city
{
	public:
		city( char str )
		{
			qnt = 0;
			name = str;
			for( int i = 0; i < 26; ++i )
				next[ i ] = NULL;
		}
		~city()
		{
			for( int i = 0; i < qnt; ++i )
				delete next[ i ];
		}
		void add( char child ) { next[ qnt++ ] = new city( child ); }
		city* find( char goal, char* path = NULL )
		{
			city* tmp;
			if( path )
				path[ strlen( path ) ] = name;
			if( goal == name )
				return this;
			else
				for( int i = 0; i < qnt; ++i )
					if( tmp = next[ i ]->find( goal, path ) )
						return tmp;
			if( path )
				path[ strlen( path )-1 ] = 0;
			return NULL;
		}
		char name;
		city* next[ 26 ];
		int qnt;
};

int main()
{
	int t, road, query;

	for( scanf( "%d", &t ); t--; )
	{
		scanf( "%d %d", &road, &query );
		char from[ road ], to[ road ], tmp[ 5000 ];
		city root( 'R' );
		queue<char>build_map;
		build_map.push( 'R' );

		for( int i = 0; i < road; ++i )
		{
			scanf( "%s", tmp );
			from[ i ] = *tmp;
			scanf( "%s", tmp );
			to[ i ] = *tmp;
		}
		while( !build_map.empty() )
		{
			city* now = root.find( build_map.front() );
			for( int i = 0; i < road; ++i )
				if( from[ i ] == build_map.front() )
				{
					now->add( to[ i ] );
					build_map.push( to[ i ] );
				}
			build_map.pop();
		}	//build graph

		for( int i = 0; i < query; ++i )
		{
			int same = 0;
			char path[ 30 ] = { 0 }, b_path[ 30 ] = { 0 }, e_path[ 30 ] = { 0 };
			scanf( "%s", tmp );
			root.find( *tmp, b_path );
			scanf( "%s", tmp );
			root.find( *tmp, e_path );

			for( same = 0; b_path[ same ] == e_path[ same ]; ++same );
			for( int i = strlen( b_path )-1; i >= same; --i )
				path[ strlen( path ) ] = b_path[ i ];
			for( int i = same-1; e_path[ i ]; ++i )
				path[ strlen( path ) ] = e_path[ i ];
			puts( path );
		}
		if( t )
			puts( "" );
	}

	return 0;
}
