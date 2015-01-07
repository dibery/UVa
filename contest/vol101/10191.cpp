#include<cstdio>
#include<algorithm>

class event
{
	public:
		event( int b = 0, int e = 0 ) : begin(b), end(e) {}
		bool operator< ( const event& c ) const { return begin < c.begin; }
		int begin, end;
};

int main()
{
	int size, bh, bm, eh, em, d = 0;
	event all[ 102 ] = { event( 0, 600 ) };

	while( scanf( "%d", &size ) == 1 )
	{
		int span = 0, start = 0;
		all[ size+1 ] = event( 1080 );
		for( int i = 1; i <= size; ++i )
		{
			scanf( "%d:%d %d:%d%*[^\n]", &bh, &bm, &eh, &em );
			all[ i ] = event( bh*60 + bm, eh*60 + em );
		}
		std::sort( all+1, all+size+1 );
		for( int i = 1; i <= size+1; ++i )
			if( all[ i ].begin - all[ i-1 ].end > span )
				span = all[ i ].begin - all[ i-1 ].end, start = all[ i-1 ].end;
		if( span < 60 )
			printf( "Day #%d: the longest nap starts at %d:%02d and will last for %d minutes.\n", ++d, start / 60, start % 60, span % 60 );
		else
			printf( "Day #%d: the longest nap starts at %d:%02d and will last for %d hours and %d minutes.\n", ++d, start / 60, start % 60, span / 60, span % 60 );
	}
}
