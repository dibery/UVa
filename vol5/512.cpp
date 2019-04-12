#include<cstdio>
#include<cstring>
#include<algorithm>

struct cell
{
	cell( int R = 0, int C = 0 ) { row = R; col = C; }
	void set( int r, int c ) { row = r; col = c; }
	void clear() { row = col = 0; }
	bool operator== ( const cell& c ) { return c.row == row && c.col == col; }
	int row, col;
};

int main()
{
	int row, col, qnt, size, t = 0, R, C, px, py, tmp[ 10 ];
	char act[ 3 ];
	bool first = true;

	while( scanf( "%d %d", &row, &col ) && row )
	{
		if( !first )
			puts( "" );
		first = false;
		cell sheet[ 51 ][ 51 ];

		for( int i = 0; i <= row; ++i )
			for( int j = 0; j <= col; ++j )
				sheet[ i ][ j ].set( i+1, j+1 );

		for( scanf( "%d", &qnt ); qnt--; )
		{
			scanf( "%s", act );

			if( !strcmp( act, "EX" ) )
			{
				int x1, y1, x2, y2;
				scanf( "%d %d %d %d", &x1, &y1, &x2, &y2 );
				std::swap( sheet[ x1-1 ][ y1-1 ], sheet[ x2-1 ][ y2-1 ] );
				continue;
			}

			scanf( "%d", &size );
			for( int i = 0; i < size; ++i )
				scanf( "%d", tmp+i ), --tmp[ i ];
			std::sort( tmp, tmp+size );

			for( int n = 0; n < size; ++n )
			{
				if( !strcmp( act, "DR" ) )
				{
					for( int i = tmp[ n ]; i < row; ++i )
						for( int j = 0; j < col; ++j )
							sheet[ i ][ j ] = sheet[ i+1 ][ j ];
					--row;
				}
				else if( !strcmp( act, "DC" ) )
				{
					for( int i = 0; i < row; ++i )
						for( int j = tmp[ n ]; j < col; ++j )
							sheet[ i ][ j ] = sheet[ i ][ j+1 ];
					--col;
				}
				else if( !strcmp( act, "IR" ) )
				{
					for( int i = row; i > tmp[ n ]; --i )
						for( int j = 0; j < col; ++j )
							sheet[ i ][ j ] = sheet[ i-1 ][ j ];
					for( int i = 0; i < col; ++i )
						sheet[ tmp[ n ] ][ i ].clear();
					++row;
				}
				else if( !strcmp( act, "IC" ) )
				{
					for( int i = 0; i < row; ++i )
						for( int j = col; j > tmp[ n ]; --j )
							sheet[ i ][ j ] = sheet[ i ][ j-1 ];
					for( int i = 0; i < row; ++i )
						sheet[ i ][ tmp[ n ] ].clear();
					++col;
				}
				for( int i = n+1; i < size; ++i )
					tmp[ i ] += *act == 'I'? 1 : -1;
			}
		}

		printf( "Spreadsheet #%d\n", ++t );
		for( scanf( "%d", &qnt ); qnt--; )
		{
			scanf( "%d %d", &R, &C );
			bool ok = false;
			for( px = 0; px < row && !ok; ++px )
				for( py = 0; py < col && !ok; ++py )
					ok |= sheet[ px ][ py ] == cell( R, C );
			if( ok )
				printf( "Cell data in (%d,%d) moved to (%d,%d)\n", R, C, px, py );
			else
				printf( "Cell data in (%d,%d) GONE\n", R, C );
		}
	}
}
