#include<cstdio>
const int N = 105, dx[] = { 1, 1, 0, -1, -1, 0, 1 }, dy[] = { 0, 1, 1, 1, -1, -1, -1 };

int main()
{
	int size, n;
	char brd[ N ][ N ] = { { 0 } }, str[ N ] = { 0 };

	scanf( "%d\n", &size );
	for( int i = 1; i <= size; ++i )
		gets( brd[ i ] + 1 );

	while( scanf( "%d", &n ) == 0 )
	{
		bool found = false;

		scanf( "%s", str );
		for( int x = 1; x <= size && !found; ++x )
			for( int y = 1; y <= size && !found; ++y )
				for( int dir = 0; dir < 7 && !found; ++dir )
				{
					bool ok = true;
					int i;
					for( i = 0; str[ i ] && ok; ++i )
						ok &= str[ i ] == brd[ x + dx[ dir ] * i ][ y + dy[ dir ] * i ];
					--i;
					if( found |= ok )
						printf( "%d,%d %d,%d\n", x, y, x + i * dx[ dir ], y + i * dy[ dir ] );
				}
		if( !found )
			puts( "Not found" );
	}
}
