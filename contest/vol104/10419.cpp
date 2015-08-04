#include<cstdio>
#include<cstring>
#include<algorithm>
const int PRIME = 125;
int prime[ PRIME ] = { 2 }, size = 1;
bool next[ 1001 ][ 15 ][ PRIME ];

bool isp( int n )
{
	for( int i = 0; prime[ i ] * prime[ i ] <= n; ++i )
		if( n % prime[ i ] == 0 )
			return false;
	return true;
}

int main()
{
	for( int i = 3; i < 300; i += 2 )
		if( isp( i ) )
			prime[ size ] = prime[ size+1 ] = i, size += 2;
	std::sort( prime, prime+size, [] ( int a, int b ) {
			char sa[ 10 ], sb[ 10 ];
			sprintf( sa, "%d", a );
			sprintf( sb, "%d", b );
			return strcmp( sa, sb ) < 0;
			} );
	for( int i = 0; i < PRIME; ++i )
		next[ 0 ][ 0 ][ i ] = true;
	for( int i = 1; i <= 1000; ++i )
		for( int j = 1; j <= 14; ++j )
			for( int k = 0; k < size; ++k )
				if( i >= prime[ k ] )
					for( int l = k+1; l < size && !next[ i ][ j ][ k ]; ++l )
						if( next[ i - prime[ k ] ][ j-1 ][ l ] )
							next[ i ][ j ][ k ] |= next[ i - prime[ k ] ][ j-1 ][ l ];

	int num, part, t = 0;

	while( scanf( "%d %d", &num, &part ) && num+part )
	{
		int pos = 0;
		printf( "CASE %d:\n", ++t );
		while( num )
		{
			for( ; pos < size; ++pos )
				if( next[ num ][ part ][ pos ] )
				{
					printf( "%d%c", prime[ pos ], prime[ pos ] == num? '\n' : '+' );
					--part;
					num -= prime[ pos++ ];
					break;
				}
			if( pos == size )
				break;
		}
		if( num )
			puts( "No Solution." );
	}
}
