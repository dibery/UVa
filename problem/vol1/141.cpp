#include <cstdio>
#include <cstring>
#include <set>
#include <cstdlib>
#include <string>
using namespace std;

void rotate( char* brd, int size )
{
	char tmp[ 3600 ] = { 0 };
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			tmp[ i*size + j ] = brd[ j*size + size-i-1 ];
	for( int i = 0; i < size; ++i )
		for( int j = 0; j < size; ++j )
			brd[ i*size + j ] = tmp[ i*size + j ];
}

int main()
{
	int n, r, c;
	char act;

	while( scanf( "%d", &n ) && n )
	{
		char brd[ 3000 ] = { 0 };
		bool ok = false;
		set<string> all;
		memset( brd, '0', n*n );
		for( int i = 0; i < 2*n; ++i )
		{
			set<string> tmp;
			scanf( "%d %d %c", &r, &c, &act );
			--r, --c;
			if( ok )
				continue;
			if( act == '+' )
				brd[ r*n + c ] = '1';
			else
				brd[ r*n + c ] = '0';

			for( int s = 0; s < 4; ++s )
			{
				if( all.find( string(brd) ) != all.end() )
				{
					printf( "Player %d wins on move %d\n", i % 2 ? 1 : 2, i+1 );
					ok = true;
					break;
				}
				else
					tmp.insert( string(brd) );
				rotate( brd, n );
			}
			all.insert( tmp.begin(), tmp.end() );
			if( i == 2*n - 1 && !ok )
				puts( "Draw" );
		}
	}
}
