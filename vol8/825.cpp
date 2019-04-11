#include<cstdio>
#include<cstring>
#include<cctype>

int main()
{
	int t, h, w, now, intersect;
	char *pos, str[ 500 ];

	for( scanf( "%d", &t ); t--; )
	{
		bool danger[ 101 ][ 101 ] = { false };
		long long int way[ 101 ][ 101 ] = { 0 };
		way[ 1 ][ 1 ] = 1;

		scanf( "%d %d\n", &h, &w );
		for( int i = 0; i < h; ++i )
		{
			gets( pos = str );
			sscanf( str, "%d", &now );
			pos = strchr( pos, ' ' );
			if( pos )
				while( *pos && *pos == ' ' )
					++pos;
			while( pos && *pos )
			{
				sscanf( pos, "%d", &intersect );
				danger[ now ][ intersect ] = true;
				pos = strchr( pos, ' ' );
				if( pos )
					while( *pos && *pos == ' ' )
						++pos;
			}
		}

		for( int i = 1; i <= h; ++i )
			for( int j = 1; j <= w; ++j )
				if( !danger[ i ][ j ] && i+j > 2 )
					way[ i ][ j ] = way[ i-1 ][ j ] + way[ i ][ j-1 ];
		printf( "%lld\n", way[ h ][ w ] );
		if( t )
			puts( "" );
	}
}
